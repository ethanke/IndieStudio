var mongoose = require('mongoose');

var Schema = mongoose.Schema;

var roomSchema = new Schema({
    clients: [{type: mongoose.Schema.Types.ObjectId, ref: 'Client'}]
});

module.exports = mongoose.model('Room', roomSchema);


