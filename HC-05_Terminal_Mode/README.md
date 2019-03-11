# HC-05_Terminal_Mode
  Neste teste é usado um componente de medição de temperatura e umidade, DHT22,
que fornece os dados para a porta serial do bluetooth.

  Como sabemos, o arduino possui limitadas portas seriais ligadas ao hardware,
porém podemos contornar essa deficiência utilizando a biblioteca "SoftwareSerial.h".
Essa biblioteca cria pinos de recepção e transmissão de dados, Rx e Tx, no arduino,
funcionando assim como uma porta serial.

  O sensor de Temperatura e Umidade também possui uma biblioteca própria que também,
é disponibilizada pela arduino.cc. Apesar de um único pino de dados apresenta dois
tipos de informações para leitura independente:

    DHT::readTemperature() //que lê a informação de temperatura
    DHT::readHumidity() //que lê a informação de umidade do sensor.
    
  A informação da porta serial criada para o bluetooth pode ser enviada para qualquer
dispositivo que contenha bluetooth e o App "Bluetooth SPP" instalado no aparelho. Essa
aplicação serve para enviar comandos e receber informações do módulo bluetooth. Funciona
basicamente como um Terminal de Comandos móvel que escreve diretamente na porta serial
do bluetooth.

  Para isso precisamos ler as informações digitadas na porta serial do bluetooth e 
dividí-las por funções, como por exemplo:

    while(!SoftwareSerial::available());
    if(SoftwareSerial::available()){
      Command = SoftwareSerial::read();
      switch(Command - 48){
        case 1: SoftwareSerial::println(F("Do this.")); break;
        case 2: SoftwareSerial::println(F("Do that.")); break;
        default: SoftwareSerial::println(F("Do nothing."); break;
      }
    }
