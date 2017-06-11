var mongoose = require('mongoose');

var Schema = mongoose.Schema;

var clientsSchema = new Schema({
    carNumber: {type: Number, default: 0},
    money: {type: Number, default: 0}
});

module.exports = mongoose.model('Client', clientsSchema);


