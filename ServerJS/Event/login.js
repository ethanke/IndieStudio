var Clients = require('../schema/Clients.js');
var Room    = require('../schema/Rooms.js');

exports.disconnect = function(socket) {
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
}

exports.login = function(socket, msg) {
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
}

exports.setCar = function(socket, msg_str) {
    console.log("RECEIVING from " + socket.id + ": \'carNum changed\': " + msg_str);
    var msg = JSON.parse(msg_str);
    Clients.find({'_id': msg.id.toObjectId()}, function(err, clientList) {
	if(clientList.length != 0) {
	    Clients.update({"_id": msg.id.toObjectId()}, {$set: {'carNumber': msg.nbr}}, function(err, result) {});
	}
    });
}
