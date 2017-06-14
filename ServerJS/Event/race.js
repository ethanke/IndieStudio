var Clients = require('../schema/Clients.js');
var Room    = require('../schema/Rooms.js');
var Race    = require('../schema/Races.js');

exports.createRace = function(socket, io, msg_str) {
    console.log("RECEIVING from " + socket.id + ": \'create race\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').populate('raceID').exec(function(err, clientList) {
	if(clientList.length != 0) {
	    if (clientList[0].roomID == null || clientList[0].raceID != null) {
		return;
	    }
	    var self = clientList[0];
	    Room.find({'_id': self.roomID}).populate('clients').populate('races').exec(function(err, roomResultF) {
		if (roomResultF.length != 0) {
		    for (var i = 0; i < roomResultF[0].races.length; i++) {
			if (roomResultF[0].races[i].raceID == msg.race_id) {
			    joinRace(socket, io, msg, self, roomResultF[0].races[i]);
			    return;
			}
		    }
		    createNewRace(socket, io, msg, self);
		}
	    });
	}
    });
}

exports.leaveRace = function(socket, io, msg_str) {
    console.log("RECEIVING from " + socket.id + ": \'leave race\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.find({'_id': msg.id.toObjectId()}, function(err, clientList) {
	if (clientList.length != 0) {
	    Race.find({'_id': clientList[0].raceID}).populate('clients').populate('leader').exec(function(err, raceResultF) {
		if (raceResultF.length != 0) {
		    for (var i = 0; i < raceResultF[0].clients.length; i++) {
			if (raceResultF[0].clients[i].socketID != socket.id) {
			    var isLeader = false;
			    if (clientList[0].shortID == raceResultF[0].leader.shortID) {
				isLeader = true;
			    }
			    var json_res = {'short_id': clientList[0].shortID, 'is_leader': isLeader};
			    if (io.sockets.connected[raceResultF[0].clients[i].socketID] != undefined) {
				console.log("EMITING   to   " + raceResultF[0].clients[i].socketID + ": \'leave race\': " + JSON.stringify(json_res));
				io.sockets.connected[raceResultF[0].clients[i].socketID].emit('leave race', json_res);
			    }
			}
		    }
		    Race.update({"_id": clientList[0].raceID}, {$pull: {'clients': clientList[0]._id}}, function(err, result) {
			Clients.update({"socketID": msg.id.toObjectId()}, {$set: {'raceID': null}}, function(err, result) {});
		    });
		}
	    });
	}
    });
}

exports.startRace = function(socket, io, msg_str) {
    console.log("RECEIVING from " + socket.id + ": \'starting race\': " + msg_str);
    var msg = JSON.parse(msg_str);
    
    setTimeout(function () {
	var json_res = {error: "!!!!  3  !!!!"};
	console.log("EMITING   to   " + socket.id + ": \'error message\': " + JSON.stringify(json_res));
	socket.emit('error message', json_res);
    }, 1000);

    setTimeout(function () {
	var json_res = {error: "!!!!  2  !!!!"};
	console.log("EMITING   to   " + socket.id + ": \'error message\': " + JSON.stringify(json_res));
	socket.emit('error message', json_res);
    }, 2000);
    
    setTimeout(function () {
	var json_res = {error: "!!!!  1  !!!!"};
	console.log("EMITING   to   " + socket.id + ": \'error message\': " + JSON.stringify(json_res));
	socket.emit('error message', json_res);
    }, 3000);
    
    setTimeout(function () {
	var json_res = {error: "!!!!  GOOOO  !!!!"};
	console.log("EMITING   to   " + socket.id + ": \'join race\': " + JSON.stringify(json_res));
	socket.emit('error message', json_res);
    }, 4000);
}

function joinRace(socket, io, msg, self, race) {
    Race.update({"_id": race._id}, {$push: {'clients': self._id}}, function(err, result) {
	if (result) {
	    Clients.update({"_id": self._id}, {$set: {'raceID': race._id}}, function(err, result) {
		if (result) {
		    Race.find({'_id': race._id}).populate('clients').exec(function(err, raceResultF) {
			if (raceResultF.length != 0) {
			    for (var i = 0; i < raceResultF[0].clients.length; i++) {
				if (raceResultF[0].clients[i].socketID != socket.id) {
				    if (io.sockets.connected[raceResultF[0].clients[i].socketID] != undefined) {
					var json_res = {'short_id': self.shortID, 'nb_total': raceResultF[0].clients.length - 1};
					console.log("EMITING   to   " + raceResultF[0].clients[i].socketID + ": \'join race\': " + JSON.stringify(json_res));
					io.sockets.connected[raceResultF[0].clients[i].socketID].emit('join race', json_res);
				    }
				}
			    }
			    
			    for (var i = 0; i < raceResultF[0].clients.length; i++) {
				if (raceResultF[0].clients[i].socketID != socket.id) {
				    var json_res = {'short_id': raceResultF[0].clients[i].shortID, 'nb_total': raceResultF[0].clients.length - 1};
				    console.log("EMITING   to   " + socket.id + ": \'join race\': " + JSON.stringify(json_res));
				    socket.emit('join race', json_res);
				}
			    }
			}
		    });
		}
	    });
	}
    });
}

function createNewRace(socket, io, msg, self) {
    var newRace = Race({
	'raceID': msg.race_id,
	'leader': self._id,
	'clients': [self._id]
    });
    newRace.save(function(err, resultRace) {
	if (resultRace) {
	    Room.update({"_id": self.roomID}, {$push: {'races': resultRace.id}}, function(err, result) {
		if (result) {
		    Clients.update({"_id": self._id}, {$set: {'raceID': resultRace.id}}, function(err, result) {
			if (result) {
			    var json_res = {'short_id': "null", 'nb_total': 0};
			    console.log("EMITING   to   " + socket.id + ": \'join race\': " + JSON.stringify(json_res));
			    socket.emit('join race', json_res);
			}
		    });   
		}
	    });
	}
    });
}
