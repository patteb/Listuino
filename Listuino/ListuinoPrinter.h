#ifndef ListuinoPrinter_h
#define ListuinoPrinter_h

#include "Arduino.h"

//Printer command macros, as of http://download.delfi.com/SupportDL/Epson/Manuals/TM-T88IV/Programming%20manual%20APG_1005_receipt.pdf

#define LF 		    Serial.write(10)
#define ESC 	    Serial.write(27)
#define GS        Serial.write(29)

#define CUT		    ESC;Serial.write(105);//Cut paper, pg.368
#define INIT	    ESC;Serial.write(64);//Printer initialisation pg.412
#define JUST(a)   ESC;Serial.write(97);Serial.write(a);// 0=left, 1=centered, 2=right, pg.165
#define FEED(n)   ESC;Serial.write(100);Serial.write(n);//feed n lines (0 <= n <= 255), pg.78
#define BOLD_ON   ESC;Serial.write(71);Serial.write(1);//enable bold, pg.109
#define BOLD_OFF  ESC;Serial.write(71);Serial.write(0);//disable bold, pg.109
#define SIZE(c)   GS;Serial.write(33);Serial.write(c);//select font-size, pg.134
#define INV_ON    GS;Serial.write(66);Serial.write(1);//white-on-black enabled, pg.136
#define INV_OFF   GS;Serial.write(66);Serial.write(0);//white-on-black disabled, pg.136

class Printer{
	public:
		Printer(int baud);
		void addItem(String item);
		void cutList();
    void printHeader();
	private:
		int _baud;
};

#endif
