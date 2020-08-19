#include<SoftwareSerial.h> //Included SoftwareSerial Library
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial s(3,1);

int i=0;

void setup() {
  //Serial S Begin at 9600 Baud
  s.begin(9600);
}

void loop() {
  //Write '123' to Serial
  if(i<5){
   delay(1000);
   s.write(123);
   i++;
  }else if (i>=5 && i<11){
    delay(1000);
    s.write(246);
    i++;
    }else{
      i=0;
      }
}
