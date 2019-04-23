#include <DHT.h>
#include <SoftwareSerial.h>
#define DHTTYPE DHT11
int Option, Time, Marker;
DHT TempHum(A0, DHTTYPE); //Define the the DHT data pin.
SoftwareSerial Cell(2,3); //Rx and Tx pins from the Bluetooth module.
  
void setup(){
  Serial.begin(9600);
  TempHum.begin();
  Cell.begin(9600);
  Marker = 0; Option = 0;
}
 
void loop(){
  if(Option == 0){
    Cell.println(F(""));
    Cell.println(F("Escolha uma das opções abaixo:"));
    Cell.println(F("============================"));
    Cell.println(F("  1  -  informe a cada segundo."));
    Cell.println(F("  2  -  informe a cada 10 segundos."));
    Cell.println(F("  3  -  Reiniciar."));
    Cell.println(F("============================"));
    Cell.println(F(""));
  }
  while(!Cell.available()) { //While there's nothing in the software port 
    if(Marker != 0){         //and the Marker steel been 0, do nothing.
      reading();
    }
  }
  Option = Cell.read();
  Cell.println(Option-48); Cell.println(F(""));
  switch(Option - 48){  //Read the value and enable the matching option.
    case 1: Time = 1; reading(); break;
    case 2: Time = 10; reading(); break;
    case 3: setup(); break;
    default: Cell.println("");
             Cell.println("Desculpe, essa opção não");
             Cell.println("está disponível.");
             Cell.println(""); Option = 0; Marker = 0; break;
  }
      
}

void reading(){
  float Humidity = TempHum.readHumidity(); //Read the Humidity data from DHT.
  float Temperature = TempHum.readTemperature(); //Read the Temperature data from DHT.
  Marker = 1;
  Cell.print("Temperatura= "); Cell.print(Temperature); Cell.print("°C ");
  Cell.print(" Umidade= "); Cell.print(Humidity); Cell.println("% ");
  delay(Time*1000);
}
