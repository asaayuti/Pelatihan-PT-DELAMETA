#include <NewPing.h>

//Inisialisasi pembuatan variable
int buzzer  = 3;
int echo    = 4;
int triger  = 5;
int ledR    = 8;
int ledY    = 9;
int ledG    = 10;
int batas   = 400; //Maksimal 400 cm
NewPing cm(triger,echo,batas);

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  pinMode(buzzer, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  }
void loop() {
  //Program yang akan dijalankan berulang-ulang
  int bacaJarak=cm.ping_cm();
  //Print ke Serial Monitor
  Serial.print(" || Data jarak:" + String(bacaJarak) + " cm");
  Serial.println();
  delay(500); //Jeda waktu perulagan seama 500 mili detik

  if(bacaJarak <=20 and bacaJarak !=0){
    Serial.print("BERHENTI");
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }else if (bacaJarak >= 21 and bacaJarak <=70){
    Serial.print("BAHAYA");
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }else {
    Serial.print("AMAN");
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(buzzer, LOW);
  }
  }
