var Clients = require('../schema/Clients.js');
var Room    = require('../schema/Rooms.js');

exports.createRace = function(socket, io, msg_str) {
    console.log("RECEIVING from " + socket.id + ": \'create race\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.find({'_id': msg.id.toObjectId()}).populate('roomID').exec(function(err, clientList) {
	if(clientList.length != 0) {
	    var self = clientList[0];
	    
	}
    });
}
