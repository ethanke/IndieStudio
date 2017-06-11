var http = require('http');
var app = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end();
});

var io = require('socket.io').listen(app);

function sendTime() {
    io.emit('time', { time: new Date().toJSON() });
}
setInterval(sendTime, 2500);

io.on('connection', function(socket) {

    console.log("Client " + socket.id + " connected.");
    socket.emit('welcome', { message: 'Welcome!', id: socket.id });

});

app.listen(3000);
