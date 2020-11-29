# EasyAT

A custom ESP 01 firmware that makes everything easier. You're welcome.

![EasyAT Logo](Logo.png)

## Cool, but why?

There's a common problem when using an ESP 01 module alongside other boards, like an Arduino UNO. While the ESP8266 inside the module is impressively powerful, the AT firmware is subpar, unintuitive, and doesn't work consistently.

Meet **EasyAT**, the easy to use, easy to mod firmware for the ESP 01 module.

## Usage

* Connect to the module using the serial pins at a speed of 9600bps
* Send commands and end with a Newline character (\n)
* Start reading the output and save it to process later
* Remove the Carriage Return (\r) and Newline (\n) characters if necesary
* Wait for the "OK" (or "ERROR") line
* Stop reading the output
* Get surprised at how straightforward the process is, and how much better than the stock firmware this solution is
* Process the stored output however you need

## Getting started

You'll need a USB - TTL Serial programmer to burn the firmware onto the chip, I recommend using a CH340G board, but a FT232RL board should also work just fine, or even an adruino, using it as an ISP (more info [here](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP))

***IMPORTANT:** To put the ESP 01 in programming mode, the pin GPIO0 must be pulled to GND. Some modding to the programming board may be needed*

The firmware may be flashed using either the Arduino IDE or PlatformIO

## Features planned

* [ ] List all WiFi access points available
* [ ] Connect to an AP from the list
* [x] Connect to a password protected AP
* [ ] Connect to an open AP
* [x] Make an HTTP GET request and wait for response
* [x] Make an HTTP POST request and wait for response
* [ ] Serve static websites that can the user can interact
* [ ] Find and remove Carriage Return (\r) characters
* [ ] Replace Arduino's `String` data type with character arrays
* [ ] Make a readable documentation

## Contributing

Pull requests are welcome. Anything that can make the project better for anyone is very appreciated. Please open an issue detailing your changes if possible.

If you choose to contribute, please put your name in the [Hall Of Fame](HallOfFame.md) so you get the recognition you deserve.

Forks are also welcome, as long as said fork remains free and open source. Failure to do so is a direct infringement of the GPLv3 licence

## License

This program is licensed under the GNU General Public License v3.0

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To learn more, please refer to the full license, found [here](LICENSE)
