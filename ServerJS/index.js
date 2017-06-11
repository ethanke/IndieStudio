var http = require('http');
var mongoose   = require('mongoose');
var app = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end();
});
var io = require('socket.io').listen(app);
var stringExtension = require('./extension/string.js');


var Clients = require('./schema/Clients.js');
var Room    = require('./schema/Rooms.js');


mongoose.connect('mongodb://localhost:27017/IDC_db');

io.on('connection', function(socket) {
    console.log("Client         " + socket.id + " connected.");

    // CLIENT DISCONNECTED
    socket.on('disconnect', function() {
	console.log("Client         " + socket.id + " disconnected.");
	Clients.find({'socketID': socket.id}, function(err, clientList) {
	    if (clientList.length != 0) {
		Room.update({"_id": clientList[0].roomID}, {$pull: {'clients': clientList[0]._id}}, function(err, result) {
		    Clients.update({"socketID": socket.id}, {$set: {'connected': false, 'roomID': null}}, function(err, result) {});
		});
	    } else {
		Clients.update({"socketID": socket.id}, {$set: {'connected': false, 'roomID': null}}, function(err, result) {});
	    }
	});
    })
    
    // ASK CURRENT CLIENT ID
    socket.emit('give your id',
		{ message: 'Welcome!' }
	       );
    
    // REGISTER NEW USER / LOGIN KNOWN USERS
    socket.on('id client is', function(msg) {
	console.log("RECEIVING from " + socket.id + ": \'id client is\': " + msg);
	
	var msg_obj = JSON.parse(msg);
	Clients.find({'_id': msg_obj.id.toObjectId()}, function(err, clientList) {
	    if(clientList.length == 0) {
		var newClient = Clients({
		    'socketID': socket.id,
		    'connected': true,
		    'shortID': "-1",
		    "roomID": null
		});
		newClient.save(function(err, result) {
		    if (result) {
			Clients.update({"_id": result.id.toObjectId()}, {$set: {'shortID': result.id.substr(result.id.length - 4)}}, function(err, result) {});
			
			var json_res = {'new_id': result._id + "", 'short_id': result.id.substr(result.id.length - 4)};
			console.log("EMITING   to   " + socket.id + ": \'change id\': " + JSON.stringify(json_res));
			socket.emit('change id', json_res);
		    }
		});
	    } else {
		Clients.update({"_id": msg_obj.id.toObjectId()}, {$set: {'socketID': socket.id, 'roomID': null, 'connected': true}}, function(err, result) {});

		var json_res = {'new_id': clientList[0]._id + "", 'short_id': clientList[0].shortID};
		console.log("EMITING   to   " + socket.id + ": \'change id\': " + JSON.stringify(json_res));
		socket.emit('change id', json_res);
	    }
	});
    });

    // CLIENT TELL US TO CHANGE HIS CAR_ID
    socket.on('carNum changed', function(msg_str) {
	console.log("RECEIVING from " + socket.id + ": \'carNum changed\': " + msg_str);
	var msg = JSON.parse(msg_str);
	Clients.find({'_id': msg.id.toObjectId()}, function(err, clientList) {
	    if(clientList.length != 0) {
		Clients.update({"_id": msg.id.toObjectId()}, {$set: {'carNumber': msg.nbr}}, function(err, result) {});
	    }
	});
    });

    // CLIENT WANT TO JOIN SOMEONE
    socket.on('joining someone', function(msg_str) {
	console.log("RECEIVING from " + socket.id + ": \'joining someone\': " + msg_str);
	var msg = JSON.parse(msg_str);
	Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
	    if(clientList.length != 0) {
		Clients.find({'shortID': msg.dest}).populate('roomID').exec(function(err, clientList2) {
		    if(clientList2.length != 0) {
			var self = clientList[0];
			var target = clientList2[0];
			
			if (target.connected == false) {
			    //TODO emit error message
			} else {
			    Room.update({"_id": self.roomID}, {$pull: {'clients': self._id}}, function(err, result) {
				if (target.roomID == null) {
				    var newRoom = Room({
					'clients': []
				    });
				    newRoom.save(function(err, resultRoom) {
					if (resultRoom) {
					    Clients.update({"_id": msg.id.toObjectId()}, {$set: {'roomID': resultRoom.id}}, function(err, resultPush1) {
						if (resultPush1) {
						    Clients.update({"shortID": msg.dest}, {$set: {'roomID': resultRoom.id}}, function(err, resultPush2) {
							if (resultPush2) {
							    Room.update({"_id": resultRoom.id}, {$push: {'clients': self._id}}, function(err, result) {
								if (result) {
					    			    Room.update({"_id": resultRoom.id}, {$push: {'clients': target._id}}, function(err, result) {

									Room.find({'_id': resultRoom.id}).populate('clients').exec(function(err, roomResultF) {
									    if (roomResultF.length != 0) {
										for (var i = 0; i < roomResultF[0].clients.length; i++) {
										    var json_res = {'connected_to': target.shortID};
										    console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'connected_to\': " + JSON.stringify(json_res));
										    io.sockets.connected[roomResultF[0].clients[i].socketID].emit('connected_to', json_res);
										}

										for (var i = 0; i < roomResultF[0].clients.length; i++) {
										    if (roomResultF[0].clients[i].socketID != socket.id) {
											var json_res = {'car_id': self.shortID, 'car_no': self.carNumber};
											console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'add car\': " + JSON.stringify(json_res));
											io.sockets.connected[roomResultF[0].clients[i].socketID].emit('add car', json_res);
										    }
										}

										for (var i = 0; i < roomResultF[0].clients.length; i++) {
										    if (roomResultF[0].clients[i].socketID != socket.id) {
											var json_res = {'car_id': roomResultF[0].clients[i].shortID, 'car_no': roomResultF[0].clients[i].carNumber};
											console.log("EMITING   to   " + socket.id + ": \'add car\': " + JSON.stringify(json_res));
											socket.emit('add car', json_res);
										    }
										}
									    }
									});
								    });
								}
							    });
							}
						    });
						}
					    });
					}
				    });
				} else {
				    Clients.update({"_id": msg.id.toObjectId()}, {$set: {'roomID': target.roomID}}, function(err, resultPush1) {
					if (resultPush1) {
					    Room.update({"_id": target.roomID}, {$push: {'clients': self._id}}, function(err, result) {
						if (result) {
						    Room.find({'_id': target.roomID}).populate('clients').exec(function(err, roomResultF) {
							if (roomResultF.length != 0) {
							    for (var i = 0; i < roomResultF[0].clients.length; i++) {
								var json_res = {'connected_to': target.shortID};
								console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'connected_to\': " + JSON.stringify(json_res));
								io.sockets.connected[roomResultF[0].clients[i].socketID].emit('connected_to', json_res);
							    }

							    for (var i = 0; i < roomResultF[0].clients.length; i++) {
								if (roomResultF[0].clients[i].socketID != socket.id) {
								    var json_res = {'car_id': self.shortID, 'car_no': self.carNumber};
								    console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'add car\': " + JSON.stringify(json_res));
								    io.sockets.connected[roomResultF[0].clients[i].socketID].emit('add car', json_res);
								}
							    }

							    for (var i = 0; i < roomResultF[0].clients.length; i++) {
								if (roomResultF[0].clients[i].socketID != socket.id) {
								    var json_res = {'car_id': roomResultF[0].clients[i].shortID, 'car_no': roomResultF[0].clients[i].carNumber};
								    console.log("EMITING   to   " + socket.id + ": \'add car\': " + JSON.stringify(json_res));
								    socket.emit('add car', json_res);
								}
							    }
							}
						    });
						    
						}
					    });
					}
				    });
				}
			    });
			}
		    }
		});
	    }
	});
    });

    // CLIENT WANT TO SEND POSITION TO OTHER PLAYER IN THE ROOM
    socket.on('send pos', function(msg_str) {
	console.log("RECEIVING from " + socket.id + ": \'send pos\': " + msg_str);
	var msg = JSON.parse(msg_str);
	Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
	    if(clientList.length != 0) {
		Room.find({'_id': clientList[0].roomID}).populate('clients').exec(function(err, roomResultF) {
		    if (roomResultF.length != 0) {
			for (var i = 0; i < roomResultF[0].clients.length; i++) {
			    if (roomResultF[0].clients[i].socketID != socket.id) {
				console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'send pos\': " + JSON.stringify(msg));
				io.sockets.connected[roomResultF[0].clients[i].socketID].emit('send pos', msg);
			    }
			}
		    }
		});
	    }
	});	
    });

    // CLIENT WANT TO SEND HIS ENGINE PARAMETERS TO OTHER PLAYER IN THE ROOM
    socket.on('send engine', function(msg_str) {
	console.log("RECEIVING from " + socket.id + ": \'send engine\': " + msg_str);
	var msg = JSON.parse(msg_str);
	Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
	    if(clientList.length != 0) {
		Room.find({'_id': clientList[0].roomID}).populate('clients').exec(function(err, roomResultF) {
		    if (roomResultF.length != 0) {
			for (var i = 0; i < roomResultF[0].clients.length; i++) {
			    if (roomResultF[0].clients[i].socketID != socket.id) {
				console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'send engine\': " + JSON.stringify(msg));
				io.sockets.connected[roomResultF[0].clients[i].socketID].emit('send engine', msg);
			    }
			}
		    }
		});
	    }
	});
    });
    
});

app.listen(3000);
