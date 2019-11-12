#include <Keyboard.h>
void setup()
{
  Keyboard.begin();
  delay(3000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(300);
  Keyboard.print("notepad");
  delay(300);
  Keyboard.press(KEY_RETURN);
  delay(300);
  Keyboard.print("Voce foi hackeado!!!");
  Keyboard.end();
}
void loop() {}
