
#include "binary.h"
#include <SD.h>
#include <string.h>
#include "Keyboard.h"

int bin2int(int numvalues, ...)
{
    int total = 0;
    va_list values;
    va_start(values, numvalues);
 
    for(;numvalues > 0; numvalues--)
        if (!(digitalRead(va_arg(values, int))) )
            total += powint(2, numvalues-1);
 
    va_end(values);
    return total;
 
}
 
int powint(int base, int exponent)
{
    int result = 1;
    for(;exponent > 0; exponent--)
        result *= base;
    return result;
}


File myFile;
boolean first = true;
String DEFAULT_FILE_NAME = "script0.txt";

void setup() {

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  int config = 0;
  if (!SD.begin(4)) {
    return;
  }


  config = bin2int(4, 0,1,2,3);

  if (config == B0000)
DEFAULT_FILE_NAME = "script0.txt";
 
  if (config == B0001)
DEFAULT_FILE_NAME = "script1.txt";

  if (config == B0010)
DEFAULT_FILE_NAME = "script2.txt";
 
  if (config == B0011)
DEFAULT_FILE_NAME = "script3.txt";
 
  if (config == B0100)
DEFAULT_FILE_NAME = "script4.txt";

  if (config == B0101)
DEFAULT_FILE_NAME = "script5.txt";

  if (config == B0110)
DEFAULT_FILE_NAME = "script6.txt";

  if (config == B0111)
DEFAULT_FILE_NAME = "script7.txt";

  if (config == B1000)
DEFAULT_FILE_NAME = "script8.txt";
 
  if (config == B1001)
DEFAULT_FILE_NAME = "script9.txt";

  if (config == B1010)
DEFAULT_FILE_NAME = "script10.txt";
 
  if (config == B1011)
DEFAULT_FILE_NAME = "script11.txt";
 
  if (config == B1100)
DEFAULT_FILE_NAME = "script12.txt";

  if (config == B1101)
DEFAULT_FILE_NAME = "script13.txt";

  if (config == B1110)
DEFAULT_FILE_NAME = "script14.txt";

  if (config == B1111)
DEFAULT_FILE_NAME = "script15.txt";


  
  myFile = SD.open(DEFAULT_FILE_NAME);
  if (myFile) {
    Keyboard.begin();
    
    String line = "";
    while (myFile.available()) {
      char m = myFile.read();
      if (m == '\n'){
        Line(line);
        line = "";
        }
        else if((int) m != 13)
        {
          line += m;
        }
    }

    Line(line);
    
    myFile.close();
  } else {
  }

  Keyboard.end();
}

void Line(String l)
{
  int space_1 = l.indexOf(" ");
  if (space_1 == -1)
  {
    Press(l);
  }
  else if (l.substring(0,space_1) == "STRING")
  {
    Keyboard.print(l.substring(space_1 + 1));
  }
  else if (l.substring(0,space_1) == "DELAY")
  {
    int delaytime = l.substring(space_1 + 1).toInt();
    delay(delaytime);
  }
  else if(l.substring(0,space_1) == "REM"){}
  else
  {
      String remain = l;

      while(remain.length() > 0)
      {
        int latest_space = remain.indexOf(" ");
        if (latest_space == -1)
        {
          Press(remain);
          remain = "";
        }
        else
        {
          Press(remain.substring(0, latest_space));
          remain = remain.substring(latest_space + 1);
        }
        delay(5);
      }
  }

  Keyboard.releaseAll();
}

int config = 0;
void Press(String b)
{
  if(b.length() == 1)
  {
    char c = b[0];
    Keyboard.press(c);
  }
  else if (b.equals("ENTER"))
  {
    Keyboard.press(KEY_RETURN);
  }
  else if (b.equals("CTRL"))
  {
    Keyboard.press(KEY_LEFT_CTRL);
  }
    else if (b.equals("SHIFT"))
  {
    Keyboard.press(KEY_LEFT_SHIFT);
  }
    else if (b.equals("ALT"))
  {
    Keyboard.press(KEY_LEFT_ALT);
  }
    else if (b.equals("GUI"))
  {
    Keyboard.press(KEY_LEFT_GUI);
  }
    else if (b.equals("UP") || b.equals("UPARROW"))
  {
    Keyboard.press(KEY_UP_ARROW);
  }
    else if (b.equals("DOWN") || b.equals("DOWNARROW"))
  {
    Keyboard.press(KEY_DOWN_ARROW);
  }
    else if (b.equals("LEFT") || b.equals("LEFTARROW"))
  {
    Keyboard.press(KEY_LEFT_ARROW);
  }
    else if (b.equals("RIGHT") || b.equals("RIGHTARROW"))
  {
    Keyboard.press(KEY_RIGHT_ARROW);
  }
    else if (b.equals("DELETE"))
  {
    Keyboard.press(KEY_DELETE);
  }
    else if (b.equals("PAGEUP"))
  {
    Keyboard.press(KEY_PAGE_UP);
  }
    else if (b.equals("PAGEDOWN"))
  {
    Keyboard.press(KEY_PAGE_DOWN);
  }
    else if (b.equals("HOME"))
  {
    Keyboard.press(KEY_HOME);
  }
    else if (b.equals("ESC"))
  {
    Keyboard.press(KEY_ESC);
  }
    else if (b.equals("INSERT"))
  {
    Keyboard.press(KEY_INSERT);
  }
    else if (b.equals("TAB"))
  {
    Keyboard.press(KEY_TAB);
  }
    else if (b.equals("END"))
  {
    Keyboard.press(KEY_END);
  }
    else if (b.equals("CAPSLOCK"))
  {
    Keyboard.press(KEY_CAPS_LOCK);
  }
    else if (b.equals("F1"))
  {
    Keyboard.press(KEY_F1);
  }
    else if (b.equals("F2"))
  {
    Keyboard.press(KEY_F2);
  }
    else if (b.equals("F3"))
  {
    Keyboard.press(KEY_F3);
  }
    else if (b.equals("F4"))
  {
    Keyboard.press(KEY_F4);
  }
    else if (b.equals("F5"))
  {
    Keyboard.press(KEY_F5);
  }
    else if (b.equals("F6"))
  {
    Keyboard.press(KEY_F6);
  }
    else if (b.equals("F7"))
  {
    Keyboard.press(KEY_F7);
  }
    else if (b.equals("F8"))
  {
    Keyboard.press(KEY_F8);
  }
    else if (b.equals("F9"))
  {
    Keyboard.press(KEY_F9);
  }
    else if (b.equals("F10"))
  {
    Keyboard.press(KEY_F10);
  }
    else if (b.equals("F11"))
  {
    Keyboard.press(KEY_F11);
  }
    else if (b.equals("F12"))
  {
    Keyboard.press(KEY_F12);
  }
    else if (b.equals("SPACE"))
  {
    Keyboard.press(' ');
  } 
}

void loop() {


}
