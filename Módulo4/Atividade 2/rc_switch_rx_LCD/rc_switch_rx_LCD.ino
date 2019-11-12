#include <RCSwitch.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
RCSwitch mySwitch = RCSwitch();
int txPin = 10;
String readString;
char bin = "";

void setup(void) {
  Serial.begin(9600);
  lcd.begin (16,2);

 lcd.setBacklight(HIGH);
 //lcd.setCursor(0,0);
 lcd.print("Leitor RF433Mhz");
 delay(1000);
  

  mySwitch.enableTransmit(txPin);
  mySwitch.enableReceive(0);
}


void loop(void) {
  
  if (mySwitch.available()) {
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
  }
  
  while (Serial.available())
  {
    delay(1); //delay to allow byte to arrive in input buffer
    char c = Serial.read();
    readString += c;
    readString.toLowerCase();
    readString.trim();
  }

  if (readString.length() >= 24)
  {
    //mySwitch.disableReceive();
    char inBin[25];
    readString.toCharArray(inBin,25);
    mySwitch.send(inBin);
    //mySwitch.enableReceive(0, output);
  }
  readString = "";


}

void output(unsigned long decimal, unsigned int length, unsigned int delay, unsigned int* raw, unsigned int protocol) {
  if (decimal == 0) {
    Serial.print("Unknown encoding.");
  } else {
    char* b = dec2binWzerofill(decimal, length);
    Serial.println( b );
  }
}

static char* bin2tristate(char* bin) {
  char returnValue[50];
  int pos = 0;
  int pos2 = 0;
  while (bin[pos]!='\0' && bin[pos+1]!='\0') {
    if (bin[pos]=='0' && bin[pos+1]=='0') {
      returnValue[pos2] = '0';
    } else if (bin[pos]=='1' && bin[pos+1]=='1') {
      returnValue[pos2] = '1';
    } else if (bin[pos]=='0' && bin[pos+1]=='1') {
      returnValue[pos2] = 'F';
    } else {
      return "not applicable";
    }
    pos = pos+2;
    pos2++;
  }
  returnValue[pos2] = '\0';
  return returnValue;
}

static char* dec2binWzerofill(unsigned long Dec, unsigned int bitLength) {
  static char bin[64]; 
  unsigned int i=0;

  while (Dec > 0) {
    bin[32+i++] = (Dec & 1 > 0) ? '1' : '0';
    Dec = Dec >> 1;
  }

  for (unsigned int j = 0; j< bitLength; j++) {
    if (j >= bitLength - i) {
      bin[j] = bin[ 31 + i - (j - (bitLength - i)) ];
    }else {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';


lcd.clear();
delay(1000);
lcd.home();

 lcd.setCursor(0,0);
 lcd.print("Leitor RF433Mhz");
 lcd.setCursor(0,1);
 lcd.print(bin);


 
  return bin;




}
