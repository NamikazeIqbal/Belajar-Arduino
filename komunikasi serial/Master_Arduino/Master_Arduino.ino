#include <SoftwareSerial.h>

char perintah[10];
char perintah1[10];

SoftwareSerial Serial2(8, 9); // RX, TX

int readline(int hurufterima, char *kata, int len){
  // berfungsi untuk membaca dan memasukkan string dari serial ke microcontroller
  static int pos = 0;
  int rpos;

  if (hurufterima > 0){
    switch (hurufterima){
      case 'r':
            break;
      case '\n':
            rpos = pos;
            pos = 0;
            return rpos;
      default:
          if (pos < len - 1){
            kata[pos++] = hurufterima;
            kata[pos] = 0;
          }

    }
  }
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0){
  readline(Serial.read(), perintah, 10);
  Serial.print("Mengirimkan perintah ke arduino Slave:");
  Serial2.println(perintah);
   while (strcmp(perintah,"on")== 0){
    digitalWrite(11,HIGH );
    delay(50);
    digitalWrite(11, LOW);
    delay(50);
    readline(Serial.read(), perintah1,10);


    if(strcmp(perintah1,"off")== 0){
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      Serial2.println(perintah1);
      break;
  
      }
    }
  }
} 
