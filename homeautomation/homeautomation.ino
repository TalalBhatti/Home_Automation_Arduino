#include <SoftwareSerial.h>
SoftwareSerial BT(10,11); //TX, RX  pins of arduino respetively
String command;

void setup()
{
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  command += c; //build the string.
  } 
  if (command.length() > 0) {
    Serial.print(command);
  if(command == "first light off") //this command will be given as an input to switch on light1
  {
    digitalWrite(A1, LOW);
  }
  else if(command == "first light on") //this command will be given as an input to switch off light1 simillarly other commands work
  {
    digitalWrite(A1, HIGH);
  }
  else if (command == "second light off")
  {
    digitalWrite (A2, LOW);
  }
  else if ( command == "second light on")
 {
   digitalWrite (A2, HIGH);
   
 }else if (command == "third light off")
  {
    digitalWrite (A0, LOW);
  }
  else if ( command == "third light on")
 {
   digitalWrite (A0, HIGH);
 }
  else if (command == "of") //using this command you can switch on all devices
 {
   digitalWrite ( A0, LOW);
   digitalWrite (A1, LOW);
   digitalWrite (A2, LOW);
 }
  else if (command == "all on")//using this command you can switch off all devices
 {
   digitalWrite (A0, HIGH);
   digitalWrite (A1, HIGH);
   digitalWrite (A2, HIGH);
 }
command="";}}
