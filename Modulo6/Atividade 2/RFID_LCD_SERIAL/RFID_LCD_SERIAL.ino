
#include <LiquidCrystal_I2C.h>
#include <Servo.h>;
#include <SPI.h>
#include <MFRC522.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 
const int servoPin = 6;
Servo servo;
String line2 = "";

void setup() {
  Serial.begin(9600);
  servo.attach (servoPin);
  SPI.begin();      
  mfrc522.PCD_Init();   
  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  lcd.print("Hardware Hacking");
  line2 = "Passe o cracha   ";
  lcd.setCursor(0,1);
  lcd.print(line2);
  delay(1000);
}
void loop() {
servo.write(360);
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println(content.substring(1));
 if (content.substring(1) == "F5 02 87 10") //UID do cartão
  {
servo.write (90);  
String line2 = "Acesso Liberado  ";
lcd.setCursor(0,0);
lcd.print(line2);
line2 = "Leonardo La Rosa";
lcd.setCursor(0,1);
lcd.print(line2);
delay(5000);
servo.write (0);  
  lcd.setCursor(0,0);
  lcd.print("Hardware Hacking");
  line2 = "Passe o cracha   ";
  lcd.setCursor(0,1);
  lcd.print(line2);
 }
 
 else   {
servo.write(360);
String line2 = "Acesso Negado    ";
lcd.setCursor(0,0);
lcd.print(line2);
line2 = "Nao Cadastrado";
lcd.setCursor(0,1);
lcd.print(line2);
delay(5000);
  lcd.setCursor(0,0);
  lcd.print("Hardware Hacking");
  line2 = "Passe o cracha   ";
  lcd.setCursor(0,1);
  lcd.print(line2);
  }
}
