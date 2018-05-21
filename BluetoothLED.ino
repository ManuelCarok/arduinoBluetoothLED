#include <SoftwareSerial.h>
 
// Inicializando puertos de comunicación
SoftwareSerial Bluetooth(11, 10); // TX/RX pins

const int ledPIN = 9;
 
void setup()  
{
  Bluetooth.begin(9600);
  pinMode(ledPIN , OUTPUT);  //definir pin como salida
}
 
String getMessage(){
  String msg = "";
  char m;
  
  while(Bluetooth.available()) {
      m = Bluetooth.read();
      msg+=String(m);
  }
  return msg;
}
 
void loop()
{
    // Verifique si se recibió un mensaje
    String msg = getMessage();
    if(msg!=""){
      if(msg == "encender"){
        digitalWrite(ledPIN , HIGH);   // poner el Pin en HIGH
        Bluetooth.println("LED encendida");
        delay(100);
      }
      if(msg == "apagar"){
        digitalWrite(ledPIN , LOW);   // poner el Pin en LOW
        Bluetooth.println("LED apagada");
        delay(100);
      }
    } 
    delay(10);
}


