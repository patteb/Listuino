#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EasyDDNS.h>

#include "ListuinoWeb.h"
#include "ListuinoPrinter.h"

// Wifi credentials
const char* ssid="********";
const char* password="********";

//DDNS credentials
const char* ddns_domain="********";
const char* ddns_username="********";
const char* ddns_pw="********";

//start instances
ESP8266WebServer server(1564);
Printer Printer(9600);

void setup() {

  
  // connect to WiFi
  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED) delay(500);

  //setup DDNS
  EasyDDNS.service("strato");
  EasyDDNS.client(ddns_domain, ddns_username, ddns_pw);
  
  // start server
  server.on("/",[](){server.send(200,"text/html", getHTML(ItemList));}); //landing page as of ListuinoWeb.h
  server.on("/addItem",handleItem);
  server.on("/cutList",handleCut);

  server.begin();

  //Start new list, mainly for header
  Printer.printHeader();

}

//MAIN loop
void loop() {
  server.handleClient();
  EasyDDNS.update(10000);
}


//handler functions
void handleCut(){
    Printer.cutList();
    ItemList="";
    server.send(200,"text/html", getHTML(htmlCut));
}

void handleItem(){
  String item = server.arg("newItem");
  Printer.addItem(item);
  
  if(ItemList.length()==0) ItemList.concat(htmlListHeader);
  ItemList.concat(item+"<br>");
  
  server.send(200,"text/html", getHTML(ItemList));  
}

String getHTML(String htmlMiddle){
  String htmlList=htmlTop+htmlMiddle+htmlBottom;
  return htmlList;
}
