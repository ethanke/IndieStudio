var Clients = require('../schema/Clients.js');
var Room    = require('../schema/Rooms.js');

exports.forwardPosition = function(socket, io, msg_str) {
//    console.log("RECEIVING from " + socket.id + ": \'send pos\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.update({'_id': msg.id.toObjectId()}, {$set: {
	'posX': msg.posX,
	'posY': msg.posY,
	'posZ': msg.posZ,
	
	'rotX': msg.rotX,
	'rotY': msg.rotY,
	'rotZ': msg.rotZ
    }}).exec(function(err, updateRes) {
	if (updateRes) {
	    Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
		if(clientList.length != 0) {
		    Room.find({'_id': clientList[0].roomID}).populate('clients').exec(function(err, roomResultF) {
			if (roomResultF.length != 0) {
			    var ennemy_pos = [];
			    for (var i = 0; i < roomResultF[0].clients.length; i++) {
				if (roomResultF[0].clients[i].socketID != socket.id) {
				    ennemy_pos.push({
					'short_id': roomResultF[0].clients[i].shortID,
					'posX': roomResultF[0].clients[i].posX,
					'posY': roomResultF[0].clients[i].posY,
					'posZ': roomResultF[0].clients[i].posZ,
					'rotX': roomResultF[0].clients[i].rotX,
					'rotY': roomResultF[0].clients[i].rotY,
					'rotZ': roomResultF[0].clients[i].rotZ
				    });
				}
			    }
			    var json_res = {'ennemy_pos': ennemy_pos};
//			    console.log("EMITING   to   " + socket.id + ": \'send pos\': " + JSON.stringify(json_res));
			    socket.emit('send pos', json_res);
			}
		    });
		}
	    });
	}
    });
}

exports.forwardEngine = function(socket, io, msg_str) {
  //  console.log("RECEIVING from " + socket.id + ": \'send engine\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.update({'_id': msg.id.toObjectId()}, {$set: {
	'LinearX': msg.LinearX,
	'LinearY': msg.LinearY,
	'LinearZ': msg.LinearZ,

	'AngularX': msg.AngularX,
	'AngularY': msg.AngularY,
	'AngularZ': msg.AngularZ,
	
	'engine': msg.engine,
	'breaking': msg.breaking,
	'steering': msg.steering
    }}).exec(function(err, updateRes) {
	if (updateRes) {
	    Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
		if(clientList.length != 0) {
		    Room.find({'_id': clientList[0].roomID}).populate('clients').exec(function(err, roomResultF) {
			if (roomResultF.length != 0) {
			    var ennemy_info = [];
			    for (var i = 0; i < roomResultF[0].clients.length; i++) {
				if (roomResultF[0].clients[i].socketID != socket.id) {
				    ennemy_info.push({
					'short_id': roomResultF[0].clients[i].shortID,
					'LinearX': roomResultF[0].clients[i].LinearX,
					'LinearY': roomResultF[0].clients[i].LinearY,
					'LinearZ': roomResultF[0].clients[i].LinearZ,
					'AngularX': roomResultF[0].clients[i].AngularX,
					'AngularY': roomResultF[0].clients[i].AngularY,
					'AngularZ': roomResultF[0].clients[i].AngularZ,
					'engine': roomResultF[0].clients[i].engine,
					'breaking': roomResultF[0].clients[i].breaking,
					'steering': roomResultF[0].clients[i].steering
				    });
				}
			    }
			    var json_res = {'ennemy_info': ennemy_info};
//			    console.log("EMITING   to   " + socket.id + ": \'send engine\': " + JSON.stringify(json_res));
			    socket.emit('send engine', json_res);
			}
		    });
		}
	    });
	}
    });
}
