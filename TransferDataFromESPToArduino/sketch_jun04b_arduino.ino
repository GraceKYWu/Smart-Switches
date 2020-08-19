int data; //Initialized variable to store recieved data
int stat;
void setup() {
  //Serial Begin at 9600 Baud 
  Serial.begin(115200);
  pinMode(8, OUTPUT);
}

void loop() {
  data = Serial.read(); //Read the serial data and store it
  delay(10);
  Serial.println(data);
  
  
  if (data == 123 || data != "nothing"){    //data == 123 && data != 246
    digitalWrite(8,HIGH);
    //delay(1000);
    }else if(data == 246){
      digitalWrite(8,LOW);
      //delay(1000);
      }else if(data == "nothing"){
        stat = digitalRead(8);
        digitalWrite(8, stat);
        }
}
