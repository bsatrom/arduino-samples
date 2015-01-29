var j5 = require('johnny-five');
var board = new j5.Board();

var LEDPIN = 13;

board.on("ready", function() {
	var led = new j5.Led(LEDPIN);
	led.strobe();
});