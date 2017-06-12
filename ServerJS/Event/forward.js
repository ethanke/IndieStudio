var Clients = require('../schema/Clients.js');
var Room    = require('../schema/Rooms.js');

exports.forwardPosition = function(socket, io, msg_str) {
    //console.log("RECEIVING from " + socket.id + ": \'send pos\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
	if(clientList.length != 0) {
	    Room.find({'_id': clientList[0].roomID}).populate('clients').exec(function(err, roomResultF) {
		if (roomResultF.length != 0) {
		    for (var i = 0; i < roomResultF[0].clients.length; i++) {
			if (roomResultF[0].clients[i].socketID != socket.id) {
			    if (io.sockets.connected[roomResultF[0].clients[i].socketID] != undefined) {
//				console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'send pos\': " + JSON.stringify(msg));
				io.sockets.connected[roomResultF[0].clients[i].socketID].emit('send pos', msg);
			    }
			}
		    }
		}
	    });
	}
    });
}

exports.forwardEngine = function(socket, io, msg_str) {
  //  console.log("RECEIVING from " + socket.id + ": \'send engine\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
	if(clientList.length != 0) {
	    Room.find({'_id': clientList[0].roomID}).populate('clients').exec(function(err, roomResultF) {
		if (roomResultF.length != 0) {
		    for (var i = 0; i < roomResultF[0].clients.length; i++) {
			if (roomResultF[0].clients[i].socketID != socket.id) {
			    if (io.sockets.connected[roomResultF[0].clients[i].socketID] != undefined) {
//				console.log("EMITING   to   " + roomResultF[0].clients[i].socketID + ": \'send engine\': " + JSON.stringify(msg));
				io.sockets.connected[roomResultF[0].clients[i].socketID].emit('send engine', msg);
			    }
			}
		    }
		}
	    });
	}
    });
}
