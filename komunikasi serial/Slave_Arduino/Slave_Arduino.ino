#include <SoftwareSerial.h>

SoftwareSerial Serial2(8, 9); // RX, TX

char kondisi[10];
char kondisi1[10];

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
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial2.println("Arduino Hidup...");
  digitalWrite(12, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    readline(Serial.read(), kondisi, 10);
    Serial2.println("Menerima perintah dari Master Arduino");
    
    while (strcmp(kondisi,"on")== 0){
      digitalWrite(12,HIGH );
      digitalWrite(11, LOW);
      delay(50);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      delay(50);
      readline(Serial.read(), kondisi1,10);


    if(strcmp(kondisi1,"off")== 0){
      digitalWrite(12, LOW);
      break;
  
      }
    }
  }
}  
