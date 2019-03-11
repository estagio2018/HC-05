#include "SoftwareSerial.h"  //Include the SoftwareSerial library
SoftwareSerial bluetooth(2, 3);  //TX, RX pins from Bluetooth
                                 //Create a new software serial

void setup() {
  Serial.begin(9600);
  Serial.println(F("Type the AT commands:"));
  bluetooth.begin(9600);  //Initialize the software serial
}

void loop() {
  //Check received a byte from hardware serial
  if (Serial.available()) {
    char ATCommand = Serial.read(); //Read and save the byte
    bluetooth.write(ATCommand);  //Send the byte to bluetooth by software serial
    Serial.print(ATCommand);
  }
  
  //Check received a byte from bluetooth by software serial
  if (bluetooth.available()) {
    while (bluetooth.available()){
      delay(15);
      char Answer = bluetooth.read(); //Read and save the byte
      Serial.print(Answer); //Print the byte to hardware serial
    }
  }
}
