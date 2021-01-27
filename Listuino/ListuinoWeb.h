const char* htmlTop="\
  <html>\
    <head>\
        <meta name=viewport content=\"initial-scale=1.0, maximum-scale=1.0, user-scalable=no\" />\
      <title>Listuino landing page</title>\
    </head>\
    <body bgcolor=#3B35E8 style=\"font-family:calibri,sans-serif;\">\
      <div style=\"padding: 10px 20px; margin: 15px 15px; background-color:#2C8FF5;border-radius: 5px 5px 5px 5px;\">\
        <div style=\"color:#393769;font-size: 300%; font-weight:bold;\">Grocery List</div><p/>\
        <form METHOD=POST action=addItem>\
          <input type=text name=newItem autofocus>\
          <input type=submit value=addItem>\
        </form><p/> \
        <form METHOD=POST action=cutList>\
          <input type=submit value=cutList>\
        </form><p/>";

const char* htmlListHeader="\
      <div style=\"color:#393769;font-size: 150%; font-weight:bold;\">Items so far:</div>";

const char* htmlCut="\
    <div style=\"color:#393769;font-size: 150%; font-weight:bold;\">List was cut!</div>";

const char* htmlBottom="\
    </div>\   
	</body>\
</html>";

String ItemList ="";
