var mongoose = require('mongoose');

var Schema = mongoose.Schema;

var clientsSchema = new Schema({
    shortID: String,
    socketID: String,
    connected: Boolean,
    carNumber: {type: Number, default: 0},
    money: {type: Number, default: 0},
    roomID: {type: mongoose.Schema.Types.ObjectId, ref: 'Room'},
    raceID: {type: mongoose.Schema.Types.ObjectId, ref: 'Race'}
});

module.exports = mongoose.model('Client', clientsSchema);


