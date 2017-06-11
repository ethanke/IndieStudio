var http = require('http');
var mongoose   = require('mongoose');
var app = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end();
});
var io = require('socket.io').listen(app);
var stringExtension = require('./extension/string.js');


var Clients = require('./schema/Clients.js');


mongoose.connect('mongodb://localhost:27017/IDC_db');

io.on('connection', function(socket) {
    console.log("Client          " + socket.id + " connected.");

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
		    'shortID': "-1"
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
		Clients.update({"_id": msg_obj.id.toObjectId()}, {$set: {'socketID': socket.id}}, function(err, result) {});

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
	Clients.find({'_id': msg.id.toObjectId()}, function(err, clientList) {
	    if(clientList.length != 0) {
		
		
		
	    }
	});
    });
    
});

app.listen(3000);
