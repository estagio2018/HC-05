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

  É importante resaltar que na função 'switch(var)' a variável lida está na faixa decimal,
apesar de que o que será aplicado pelo 'case' está na função de caracter, isto é, o 0 literal
está como 48 em decimal segundo a tabela ASCII no link abaixo:

   https://www.google.com/url?sa=i&source=images&cd=&ved=2ahUKEwi83K2g2PrgAhWCHLkGHbb2CJAQjRx6BAgBEAU&url=%2Furl%3Fsa%3Di%26source%3Dimages%26cd%3D%26ved%3D2ahUKEwi83K2g2PrgAhWCHLkGHbb2CJAQjRx6BAgBEAU%26url%3Dhttp%253A%252F%252Fgabihbia1415.blogspot.com%252F2014%252F10%252Ftabela-ascii.html%26psig%3DAOvVaw08UYtt2afzWnrLCWy_pRkX%26ust%3D1552414345783552&psig=AOvVaw08UYtt2afzWnrLCWy_pRkX&ust=1552414345783552

  Isso acontece devido a leitura da porta serial através do bluetooth.
  
  É importante também configurar o terminal de entrada "Bluetooth SPP" para que não crie uma
nova linha de envio gerando erro na leitura da porta.
