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
    console.log("Client " + socket.id + " connected.");
    
    socket.emit('give your id',
		{ message: 'Welcome!' }
	       );
    
    socket.on('id client is', function(msg) {
	var msg_obj = JSON.parse(msg);
	Clients.find({'_id': msg_obj.id.toObjectId()}, function(err, clientList) {
	    if(clientList.length != 0)
	    {
		
	    }
	    else
	    {
		var newClient = Clients();
		newClient.save(function(err, result) {
		    if (result)
		    {
			socket.emit('change id', {'new_id': result._id + ""});
		    }
		    else
		    {
			//FAIL SAVE BDD
		    }
		});
	    }
	});
    });
    
});

app.listen(3000);
