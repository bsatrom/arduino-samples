var j5 = require("johnny-five");
var board = new j5.Board();
var LEDPIN = 8;
var BTNPIN = 7;
var ledOn = false;

board.on("ready", function() {
	var led = new j5.Led(LEDPIN);
	var btn = new j5.Button(BTNPIN);

	btn.on('hit', function() {
		led.on();
	});

	btn.on('release', function() {
		led.off();
	});
});