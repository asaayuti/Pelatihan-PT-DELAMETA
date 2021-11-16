#include <NewPing.h>

//Inisialisasi
int ledMerah = PC13;
int ledKuning = PC14;
int ledHijau = PC15;
int flame = PA0;
int pir = PA1;
int trig = PA4;
int echo = PB4;
int batas = 400; // batas mak 400cm
int kunci = 0;
NewPing ultrasonik(trig, echo, batas);

void setup() {
  //Deklarasi Pin I/O
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
//  pinMode(pir, INPUT); //Karena di pin analog
  
  //Serail begin
  Serial.begin(9600);
}

void loop() {
  //Baca data
  int bacaFlame = analogRead(flame);
  int bacaPIR = digitalRead(pir);
  int bacaUltrasonik = ultrasonik.ping_cm();

  //Merubah data
  bacaFlame = map(bacaFlame,0,4095,255,0);
  bacaPIR = map(bacaPIR,0,1,1,0);
  
  //Serial print
  Serial.print("Data jarak: " + String(bacaUltrasonik) + " cm");
  Serial.print(" Data flame: " + String(bacaFlame));
  Serial.println(" Data pir: " + String(bacaPIR));
//  delay(1000);

  //Logika
  //Sensor Flame
  if(bacaFlame > 0 and kunci == 0){
    kunci = 1;
    delay(500);
  }else if(bacaFlame > 0 and kunci == 1){
    kunci = 0;
    delay(500);
  }

  //Sensor PIR
  if(bacaPIR==1 and kunci == 0){
    kunci = 1;
    delay(500);
  }else if(bacaPIR==1 and kunci == 1){
    kunci = 0;
    delay(500);
  }
  
  if(bacaUltrasonik > 20 and kunci == 1){
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, LOW);
      delay(500);
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledHijau, LOW);
      delay(500);
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, HIGH);
      delay(500);
   
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledHijau, LOW);
      delay(500);
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, LOW);
      
    }else if(bacaUltrasonik < 20 and bacaUltrasonik >10 and kunci ==1){
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledHijau, HIGH);
      delay(1000);
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, LOW);
      delay(1000);
    }else if(kunci ==1){
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledHijau, HIGH);
      delay(100);
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, LOW);
      delay(100);
    }
}
