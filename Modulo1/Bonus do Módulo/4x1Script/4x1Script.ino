#include "DigiKeyboard.h"

void setup(){ 
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);

 }

 void loop() {
  if (digitalRead(0)==HIGH){
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  
  }
  if (digitalRead(1)==HIGH){
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(250);
  DigiKeyboard.print("Sua Senha");
  DigiKeyboard.delay(250);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  
  if (digitalRead(2)==HIGH){
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("notepad");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(800);
  DigiKeyboard.print("Hello World");
  }

  if (digitalRead(4)==HIGH){
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("http://www.acaditi.com.br");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  }

DigiKeyboard.delay(100);
 }
