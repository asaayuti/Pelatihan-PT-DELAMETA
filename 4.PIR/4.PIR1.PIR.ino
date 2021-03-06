//Inisialisasi

#include "pitches.h"
int pir    = 4;
int buzzer = 5;
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  //Baca Data
  int bacapir = digitalRead(pir);

  //Print Serial
//  Serial.print("Nilai PIR : ");
//  Serial.print(bacapir);
  Serial.println();   //Untuk Enter

  if(bacapir == 1){
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(5, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
//    for(int i=500; i<800; i++){
//      tone(buzzer, i);
//      delay(15);
//    }
//    for(int i=800; i>500; i--){
//      tone(buzzer, i);
//      delay(15);
//    }
//    digitalWrite(buzzer, HIGH);
//    Serial.println("ADA MALING !!!");
//    
  }else {
    digitalWrite(buzzer, LOW);
  }

}
