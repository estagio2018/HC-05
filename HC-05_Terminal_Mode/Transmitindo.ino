#include <DHT.h>
//#include <DHT_U.h>
#include "SoftwareSerial.h"
#define dht_pin A0
#define DHTTYPE DHT22
String cont, Answer;
int Option, Speed;
int Time;
DHT TempHum(dht_pin, DHTTYPE); //Define as pinagens do sensor
SoftwareSerial Cell(2,3);
int marcador;
  
void setup(){
  Serial.begin(9600);
  //delay(1000); // Aguarda 1 seg antes de acessar as informações do sensor
  TempHum.begin();
  Cell.begin(9600);
  marcador = 0;
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
  /*if(Serial.available()){
    Answer = Serial.read();
    Serial.println(Answer); Cell.println(Answer);
  }*/
  while(!Cell.available())
  {
    if(marcador != 0){
      reading();
  }
  }
  Option = Cell.read();
   //Serial.println(Option);
  /* //Test Port Information
  Cell.print(F("=="));
  Cell.write(Option);
  Cell.println(F("=="));
  Cell.println(F(""));*/

  switch(Option-48){
    case 1: Time = 1; reading(); break;
    case 2: Time = 2; reading(); break;
    case 3: Time = 5; reading(); break;
    case 4: Time = 10; reading(); break;
    case 5: Time = 30; reading(); break;
    case 6: Time = 60; reading(); break;
    case 7: Time = 300; reading(); break;
    case 8: Time = 600; reading(); break;
    case 9: setup(); break;
    default:  /*Cell.print(F("=*="));
              Cell.write(Speed);
              Cell.print(F("=*="));*/
             Cell.println("");
             Cell.println("Desculpe, essa opção não");
             Cell.println("está disponível.");
             Cell.println(""); 
             Cell.println("Por favor digite uma das opções a seguir:"); break;
    }
      
}

void reading(){
  float Humidity = TempHum.readHumidity();
  float Temperature = TempHum.readTemperature();
  marcador = 1;
  // Mostra os valores lidos, na serial
  Serial.print("Temperatura= "); Serial.print(Temperature); Serial.print("°C ");
  Serial.print(" Umidade= "); Serial.print(Humidity); Serial.println("% ");
  delay(Time*1000);
  Cell.print("Temperatura= "); Cell.print(Temperature); Cell.print("°C ");
  Cell.print(" Umidade= "); Cell.print(Humidity); Cell.println("% ");
  delay(Time*1000);
}
