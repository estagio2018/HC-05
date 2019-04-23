# HC-05_Setting_Mode
  Nesse arquivo segue a seguência de comandos/códigos que
iniciará e configurará o módulo aos parâmetros desejados ao
qual o usuário (editor/programador) preferir.

  Essa seguência de comandos recebe o nome de AT Commands,
que serão inceridos (digitados) na porta serial do seu
computador, recebendo assim uma resposta do módulo trabalhado.

  É importante destacar três passos para o uso dessa função:
  
    i. O módulo só funcionará se o pino "key" estiver devidamente conectado ao Vcc
      para que a chave de função do módulo esteja ativada;
    
    ii. Apesar de o módulo ser alimentado por 5V as portas Tx e Rx suportam uma
      variação de 1,8V~3,6V, portanto se faz necessário um divisor de tensão: (R2=2R1).
    
    iii. Antes de alimentar a placa é preciso estar precionado a chave para que o
      módulo entenda que deve entrar no modo AT Commands.
    
    
  Desta forma segue alguns dos comandos utilizados para a
configuração do módulo:

    1. Comando de Teste:
      Comando: "AT"                                 Resposta: "OK"
      
    2. Reset:
      Comando: "AT+RESET"                           Resposta: "OK"
      
    3. Obter versão da placa:
      Comando: "AT+VERSION?"                        Resposta: "+VERSION:<Param>"
                                                              "OK"
                                        
    4. Restaurar definições de fabrica:
      Comando: "AT+ORGL"                            Resposta: "OK"
      
                  Obs.: Definições de fabrica: Modo escravo, PIN: 1234,
                        Nome do dispositivo: H-C-2010-06-01 e taxa de
                        transferência de 38400bits/s.
              
    5. Obter endereço do módulo:
      Comando: "AT+ADDR?"                           Resposta: "+ADDR:<Param>"
                                                              "OK"
                  Obs.: Endereço Bluetooth: "NAP:UAP:LAP"
    
    6. Mudar ou Conferir o nome do módulo:
      Comando: "AT+NAME=<Param>"                    Resposta: "OK"
               "AT+NAME?"                                     "+NAME:<Param>"
                                                              "OK(/FAIL)"
    
    7. Mudar ou Conferir o PIN:
      Comando: "AT+PSWD=<Param>"                    Resposta: "OK"
               "AT+PSWD?"                                     "+ PSWD :<Param>"
                                                              "OK"
                  Obs.: O PIN de fábrica costuma ser "1234".
    
    8. Mudar ou Conferir o parametro serial:
      Comando: "AT+UART=<Param>,<Param2>,<Param3>"  Resposta: "OK"
               "AT+UART=?"                                    "+UART=<Param>,<Param2>,<Param3>"
                                                              "OK"
                                                              
                  Obs.: Param1:Taxa de tranmissão, Param2:Stop bit
                        e Param3:Paridade.
        
