# Listuino
ESP8266-based webserver application to add items to an grocery list on a thermal printer

Basic functionality is as follows:
- ESP8266 D1 mini is connected to an thermal printer via UART
- ESP8266 is connected to home WiFi and runs a webserver, which hosts a simple HTML-document
	+ HTML-document consists of simple forms to add Items and to cut the paper (so that the list can be taken)
- webserver listens to calls from that HTML-form, taking the following actions:
	+ addItem: directly print a new line via serial connection
	+ cutList: feed some paper, cut, print new header

Directories:
- web: storage for HTML-files (maybe CSS later) so they can be edited comfortably 