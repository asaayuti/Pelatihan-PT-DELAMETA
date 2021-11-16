//Inisialisasi

#include "pitches.h"
int ldr    = A0;
int led    = 5;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  //Baca Data
  int bacaldr = analogRead(ldr);
      bacaldr = map(bacaldr,0,1024,0,255);
      //0,1024 nilai ldr 0 sampai 1024
      //0,255 nilai yang diubah atau nilai led pwn 0-255
  //Print Serial
  Serial.print("Nilai LDR : ");
  Serial.print(bacaldr);
  Serial.println();   //Untuk Enter
  
  analogWrite(led, bacaldr);

//semakin terang semakin redup lednya
}
