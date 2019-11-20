#include <RHReliableDatagram.h>                      // biblioteca Radiohead reliableDatagram
#include <RH_ASK.h>                                  // biblioteca Radiohead ASK
#include <SPI.h>                                     // biblioteca SPI
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
#define TX_ADDRESS 1                                 // endereÃ§o do transmissor
#define RX_ADDRESS 2                                 // endereÃ§o do receptor 

uint8_t count = 0;                                   // contador
uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];                 // buffer da mensagem
uint8_t tamanho;                                     // tamanho da mensagem
uint8_t from;                                        // endereÃ§o de quem transmite

RH_ASK driver;                                       // instÃ¢ncia RH ASK
RHReliableDatagram gerente(driver, RX_ADDRESS);      // configurando o gerenciador


void setup(void) {
  Serial.begin(9600);
  lcd.begin (16,2);

 lcd.setBacklight(HIGH);
 //lcd.setCursor(0,0);
 lcd.print("Leitor RF433Mhz");
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


 // Aqui vamos movimentar todo o display X posições para a ESQUERDA.
  for(int posi_LCD = 0; posi_LCD < 36; posi_LCD ++)
  {
    lcd.setCursor(16,1);
    lcd.scrollDisplayLeft();  //Essa é a função que faz as letras se deslocarem
 
    delay(250);         // Quanto menor o tempo, mais rápido será o deslocamento
  }


lcd.clear();
delay(1000);
lcd.home();

 lcd.setCursor(0,0);
 lcd.print("Acadi-TI");
 lcd.setCursor(0,1);
 lcd.print((char*)buf);
    }

  }
}
