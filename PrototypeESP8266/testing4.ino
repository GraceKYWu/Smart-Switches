#include <Wire.h>
#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "Wolf_mi3"
#define STAPSK  "24295593"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

///////////////////////////////////SET UP/////////////////////////////////////
void setup() {
  Serial.begin(115200);
  Wire.begin(D1,D2);

  //pinMode(0, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  Serial.print("connect to wifi start");
  connecttowifi();
  Serial.print("connect to wifi done");
}

/////////////////////////////////LOOP///////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
 
  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println(F("new client"));

  client.setTimeout(5000); // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

// Match the request
  int val;
  if (req.indexOf(F("/kitchen/0")) != -1) {
    val = 1;
    onoroff(val);
  } else if (req.indexOf(F("/kitchen/1")) != -1) {
    val = 2;
    onoroff(val);
  } else if (req.indexOf(F("/livroom/0")) != -1) {
    val = 3;
    onoroff(val);
  }else if (req.indexOf(F("/livroom/1")) != -1) {
    val = 4;
    onoroff(val);
  }else if (req.indexOf(F("/both/0")) != -1) {
    val = 5;
    onoroff(val);
  }else if (req.indexOf(F("/both/1")) != -1) {
    val = 6;
    onoroff(val);
  }else {
    Serial.println(F("invalid request"));
    
  }

    
    delay(100);
  // read/ignore the rest of the request
  // do not client.flush(): it is for output only, see below
  while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }
 
      Serial.print(val);

  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now "));
  client.print((val) ? F("high") : F("low"));
  client.print(F("<br><br>Click <a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/gpio/1'>here</a> to switch LED GPIO on, or <a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/gpio/0'>here</a> to switch LED GPIO off.</html>"));

  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
     
}

////////////////////////////CONNECT TO WIFI SETTING/////////////////////////////
void connecttowifi(){
   Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());
  }
//////////////////////transmit data////////

void onoroff(int num){
   switch (num){
    case 1:
    digitalWrite(4, HIGH);
    break;
    case 2:
    digitalWrite(4, LOW);
    break;
    case 3:
    digitalWrite(5, HIGH);
    break;
    case 4:
    digitalWrite(5, LOW);
    break;
    case 5:
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    break;
    case 6:
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    break;
    }
  }
