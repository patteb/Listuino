#include "Arduino.h"
#include "ListuinoPrinter.h"

Printer::Printer(int baud){
	Serial.begin(baud);
	_baud = baud;
	INIT;
}

void Printer::addItem(String item){
  Serial.println(item);
}

void Printer::cutList(){
  FEED(5);
  CUT;
  printHeader();
}

void Printer::printHeader(){
  JUST(1); //center-aligned
  BOLD_ON;
  SIZE(32+2); //(triple width+ triple height)
  Serial.println("Einkauf");
  FEED(1);
  SIZE(0);
  BOLD_OFF;
  JUST(0);//left-aligned
}
