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
					var json_res = {'short_id': self.shortID};
					console.log("EMITING   to   " + raceResultF[0].clients[i].socketID + ": \'join race\': " + JSON.stringify(json_res));
					io.sockets.connected[raceResultF[0].clients[i].socketID].emit('join race', json_res);
				    }
				}
			    }
			    
			    for (var i = 0; i < raceResultF[0].clients.length; i++) {
				if (raceResultF[0].clients[i].socketID != socket.id) {
				    var json_res = {'short_id': raceResultF[0].clients[i].shortID};
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
			}
		    });   
		}
	    });
	}
    });
}
