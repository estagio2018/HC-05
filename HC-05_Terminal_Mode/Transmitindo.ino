#include <DHT.h>
#include "SoftwareSerial.h"
#define DHTTYPE DHT22
String cont, Answer;
int Option, Speed, Time, Marker;
DHT TempHum(A0, DHTTYPE); //Define the the DHT data pin.
SoftwareSerial Cell(2,3); //Rx and Tx pins from the Bluetooth module.
  
void setup(){
  Serial.begin(9600);
  TempHum.begin();
  Cell.begin(9600);
  Marker = 0;
}
 
void loop(){
  Cell.println(F(""));
  Cell.println(F("Escolha uma das opções abaixo:"));
  Cell.println(F("============================"));
  Cell.println(F("  1  -  informe a cada segundo."));
  Cell.println(F("  2  -  informe a cada 2 segundos."));
  Cell.println(F("  3  -  informe a cada 5 segundos."));
  Cell.println(F("  4  -  informe a cada 10 segundos."));
  Cell.println(F("  5  -  informe a cada 30 segundos."));
  Cell.println(F("  6  -  informe a cada minuto."));
  Cell.println(F("  7  -  informe a cada 5 minutos."));
  Cell.println(F("  8  -  informe a cada 10 minutos."));
  Cell.println(F("  9  -  Reiniciar."));
  Cell.println(F("============================"));
  Cell.println(F(""));
  while(!Cell.available()) { //While there's nothing in the software port 
    if(Marker != 0){         //and the Marker steel been 0 do nothing.
      reading();
    }
  }
  Option = Cell.read();
  switch(Option-48){  //Read the value and enable the matching option.
    case 1: Time = 1; reading(); break;
    case 2: Time = 2; reading(); break;
    case 3: Time = 5; reading(); break;
    case 4: Time = 10; reading(); break;
    case 5: Time = 30; reading(); break;
    case 6: Time = 60; reading(); break;
    case 7: Time = 300; reading(); break;
    case 8: Time = 600; reading(); break;
    case 9: setup(); break;
    default: Cell.println("");
             Cell.println("Desculpe, essa opção não");
             Cell.println("está disponível.");
             Cell.println(""); 
             Cell.println("Por favor digite uma das opções a seguir:"); break;
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
