#include <SPI.h>
#include <SD.h>
#include <string.h>
#include "Keyboard.h"
#include "Mouse.h"

#define KEYPAD_0 234
#define KEYPAD_1 225
#define KEYPAD_2 226
#define KEYPAD_3 227
#define KEYPAD_4 228
#define KEYPAD_5 229
#define KEYPAD_6 230
#define KEYPAD_7 231
#define KEYPAD_8 232
#define KEYPAD_9 233
#define KEYPAD_ASTERIX 221
#define KEYPAD_ENTER 224
#define KEYPAD_MINUS 222
#define KEYPAD_PERIOD 235
#define KEYPAD_PLUS 223
#define KEYPAD_SLASH 220
#define PRINTSCREEN 206 
#define KEY_AT 64
#define KEY_MINOR 60
#define KEY_MAJOR 62

#define KEY_COLON 63
#define KEY_SEMICOLON 47



File myFile2; 
File myFile;
boolean first = true;
String DEFAULT_FILE_NAME = "script.txt";
#define BAUD_RATE 57200

#define ExternSerial Serial1
String bufferStr = "";
String last = "";
int defaultDelay = 0;

void Linex(String l)
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


void Line(String _line)
{
  int firstSpace = _line.indexOf(" ");
  if(firstSpace == -1) Press(_line);
  else if(_line.substring(0,firstSpace) == "STRING"){
    for(int i=firstSpace+1;i<_line.length();i++) Keyboard.write(_line[i]);
  }
  else if(_line.substring(0,firstSpace) == "DELAY"){
    int delaytime = _line.substring(firstSpace + 1).toInt();
    delay(delaytime);
  }
  else if(_line.substring(0,firstSpace) == "DEFAULTDELAY") defaultDelay = _line.substring(firstSpace + 1).toInt();
  else if(_line.substring(0,firstSpace) == "REM"){} //nothing :/
  else if(_line.substring(0,firstSpace) == "REPLAY") {
    int replaynum = _line.substring(firstSpace + 1).toInt();
    while(replaynum)
    {
      Line(last);
      --replaynum;
    }
  } else{
      String remain = _line;

      while(remain.length() > 0){
        int latest_space = remain.indexOf(" ");
        if (latest_space == -1){
          Press(remain);
          remain = "";
        }
        else{
          Press(remain.substring(0, latest_space));
          remain = remain.substring(latest_space + 1);
        }
        delay(5);
      }
  }

  Keyboard.releaseAll();
  delay(defaultDelay);
}


void Press(String b){
  if(b.length() == 1) Keyboard.press(char(b[0]));
  else if (b.equals("ENTER")) Keyboard.press(KEY_RETURN);
  else if (b.equals("CTRL")) Keyboard.press(KEY_LEFT_CTRL);
  else if (b.equals("SHIFT")) Keyboard.press(KEY_LEFT_SHIFT);
  else if (b.equals("ALT") || b.equals("ALTLEFT")) Keyboard.press(KEY_LEFT_ALT);
  else if(b.equals("ALT_RIGHT") || b.equals("ALTRIGHT")) Keyboard.press(KEY_RIGHT_ALT);
  else if (b.equals("GUI")) Keyboard.press(KEY_LEFT_GUI);
  else if (b.equals("UP") || b.equals("UPARROW")) Keyboard.press(KEY_UP_ARROW);
  else if (b.equals("DOWN") || b.equals("DOWNARROW")) Keyboard.press(KEY_DOWN_ARROW);
  else if (b.equals("LEFT") || b.equals("LEFTARROW")) Keyboard.press(KEY_LEFT_ARROW);
  else if (b.equals("RIGHT") || b.equals("RIGHTARROW")) Keyboard.press(KEY_RIGHT_ARROW);
  else if (b.equals("DELETE")) Keyboard.press(KEY_DELETE);
  else if (b.equals("PAGEUP")) Keyboard.press(KEY_PAGE_UP);
  else if (b.equals("PAGEDOWN")) Keyboard.press(KEY_PAGE_DOWN);
  else if (b.equals("HOME")) Keyboard.press(KEY_HOME);
  else if (b.equals("ESC")) Keyboard.press(KEY_ESC);
  else if (b.equals("BACKSPACE")) Keyboard.press(KEY_BACKSPACE);
  else if (b.equals("INSERT")) Keyboard.press(KEY_INSERT);
  else if (b.equals("TAB")) Keyboard.press(KEY_TAB);
  else if (b.equals("END")) Keyboard.press(KEY_END);
  else if (b.equals("CAPSLOCK")) Keyboard.press(KEY_CAPS_LOCK);
  else if (b.equals("F1")) Keyboard.press(KEY_F1);
  else if (b.equals("F2")) Keyboard.press(KEY_F2);
  else if (b.equals("F3")) Keyboard.press(KEY_F3);
  else if (b.equals("F4")) Keyboard.press(KEY_F4);
  else if (b.equals("F5")) Keyboard.press(KEY_F5);
  else if (b.equals("F6")) Keyboard.press(KEY_F6);
  else if (b.equals("F7")) Keyboard.press(KEY_F7);
  else if (b.equals("F8")) Keyboard.press(KEY_F8);
  else if (b.equals("F9")) Keyboard.press(KEY_F9);
  else if (b.equals("F10")) Keyboard.press(KEY_F10);
  else if (b.equals("F11")) Keyboard.press(KEY_F11);
  else if (b.equals("F12")) Keyboard.press(KEY_F12);
  else if (b.equals("SPACE")) Keyboard.press(' ');


else if (b.equals("COLON")) Keyboard.write(KEY_COLON);
else if (b.equals("SEMICOLON")) Keyboard.write(KEY_SEMICOLON);
else if (b.equals("ATAT")) Keyboard.write(KEY_AT);
else if (b.equals("MINOR")) Keyboard.write(KEY_MINOR);
else if (b.equals("MAJOR")) Keyboard.write(KEY_MAJOR);


  else if(b.equals("NUM_SLASH")) Keyboard.write(KEYPAD_SLASH);
  else if(b.equals("NUM_ASTERIX")) Keyboard.write(KEYPAD_ASTERIX);
  else if(b.equals("NUM_ENTER")) Keyboard.write(KEYPAD_ENTER);
  else if(b.equals("NUM_Minus")) Keyboard.write(KEYPAD_MINUS);
  else if(b.equals("NUM_PERIOD")) Keyboard.write(KEYPAD_PERIOD);
  else if(b.equals("NUM_PLUS")) Keyboard.write(KEYPAD_PLUS);

  else if(b.equals("CLICK")  || b.equals("CLICK_LEFT") || b.equals("MOUSECLICK")) Mouse.click();
  else if(b.equals("CLICK_RIGHT")) Mouse.click(MOUSE_RIGHT);
  else if(b.equals("CLICK_MIDDLE")) Mouse.click(MOUSE_MIDDLE);
  
  else if(b.equals("PRESS") || b.equals("PRESS_LEFT")) Mouse.press();
  else if(b.equals("PRESS_LEFT")) Mouse.press(MOUSE_RIGHT);
  else if(b.equals("PRESS_MIDDLE")) Mouse.press(MOUSE_MIDDLE);
  else if(b.equals("RELEASE") || b.equals("RELEASE_LEFT")) Mouse.release();
  else if(b.equals("RELEASE_LEFT")) Mouse.release(MOUSE_RIGHT);
  else if(b.equals("RELEASE_MIDDLE")) Mouse.release(MOUSE_MIDDLE);
  
  //else Serial.println("not found :'"+b+"'("+String(b.length())+")");
}

void setup() {
  if (!SD.begin(4)) {
    return;
  }
  

  myFile = SD.open(DEFAULT_FILE_NAME);
  if (myFile) {
    Keyboard.begin();
    
    String linex = "";
    while (myFile.available()) {
      char m = myFile.read();
      if (m == '\n'){
        Linex(linex);
        linex = "";
        }
        else if((int) m != 13)
        {
          linex += m;
        }
    }
    Linex(linex);
    
    myFile.close();






  } else {
  }

  myFile2 = SD.open("log.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile2) {
    myFile2.println("testing 1, 2, 3.");
    // close the file:
    myFile2.close();
  } else {
  }

  Keyboard.end();
  
  Serial.begin(BAUD_RATE);
  ExternSerial.begin(BAUD_RATE);

  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);

  Keyboard.begin();
  
}

void loop() {
  if(ExternSerial.available()) {
    bufferStr = ExternSerial.readStringUntil("END");
    Serial.println(bufferStr);
  }
  
  if(bufferStr.length() > 0){
    
    bufferStr.replace("\r","\n");
    bufferStr.replace("\n\n","\n");
    
    while(bufferStr.length() > 0){
      int latest_return = bufferStr.indexOf("\n");
      if(latest_return == -1){
        Serial.println("run: "+bufferStr);
        Line(bufferStr);
        bufferStr = "";
      } else{
        Serial.println("run: '"+bufferStr.substring(0, latest_return)+"'");
        Line(bufferStr.substring(0, latest_return));
        last=bufferStr.substring(0, latest_return);
        bufferStr = bufferStr.substring(latest_return + 1);
      }
    }
    
    bufferStr = "";
    ExternSerial.write(0x99);
    Serial.println("done");
  }
}

