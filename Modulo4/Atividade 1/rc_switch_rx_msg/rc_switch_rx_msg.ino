#include <RHReliableDatagram.h>                      // biblioteca Radiohead reliableDatagram
#include <RH_ASK.h>                                  // biblioteca Radiohead ASK
#include <SPI.h>                                     // biblioteca SPI

 
#define TX_ADDRESS 1                                 // endereÃ§o do transmissor
#define RX_ADDRESS 2                                 // endereÃ§o do receptor 

uint8_t count = 0;                                   // contador
uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];                 // buffer da mensagem
uint8_t tamanho;                                     // tamanho da mensagem
uint8_t from;                                        // endereÃ§o de quem transmite

RH_ASK driver;                                       // instÃ¢ncia RH ASK
RHReliableDatagram gerente(driver, RX_ADDRESS);      // configurando o gerenciador


void setup(void) {
 delay(1000);
 Serial.begin(9600);                                // inicializa console serial 9600 bps
 if (!gerente.init())                               // se a inicializaÃ§Ã£o do gerenciador falhar
    Serial.println("Falha na inicializacao");        // print na console serial
}


void loop(void) {
  
 if (gerente.available())                           // se gerenciador estiver ativo
  {
    tamanho = sizeof(buf);                           // determina o tamanho do buffer
    if (gerente.recvfromAck(buf, &tamanho, &from))   // se o gerenciador receber mensagem
    {
      Serial.print("Recebido de: 0x");               // print na console serial
      Serial.print(from, HEX);                       // print do endereÃ§o do transmissor em Hexadecimal
      Serial.print(": ");                            // print na console serial
      Serial.println((char*)buf);                    // print da mensagem recebida
    }

  }
}
