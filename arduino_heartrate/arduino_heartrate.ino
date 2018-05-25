#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(2,3);
String value;
String out; 
int counter;
int flag;
String string;
int counterLine;
 
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  BTSerial.begin(9600);
  out="";
  Serial.println("Hello world");
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  flag=0;
 
}
 
void loop() {
  if (BTSerial.available() > 0) {
    byte a = Serial.write(BTSerial.read());
    if (a==(byte) 1){
      counterLine=0;
      counter=0;
      flag=1;
    }
  }
  if (flag==1 && counter<1500){
    value=analogRead(A0);
    out=out+value;
    counter++;
    counterLine++;
    if (counterLine==20){
      Serial.println(out);
      BTSerial.println(out);
      counterLine=0;
      out="";
    }else{
      out=out+" ";
    }
  }
  delay(6);
}
