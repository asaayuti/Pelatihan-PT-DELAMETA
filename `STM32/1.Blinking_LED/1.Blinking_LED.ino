//Inisialisasi
int ledMerah = PA0;
int ledKuning = PA1;
int ledHijau = PA2;
int tombolMerah = PB6;
int tombolKuning = PB4;
int tombolHijau = PB5;
//char led;

void setup() {
//  for(led=13; led<16; led++){
//    pinMode(PC[led], OUTPUT);
//  }
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(tombolMerah, INPUT);
  pinMode(tombolKuning, INPUT);
  pinMode(tombolHijau, INPUT);
}

void loop() {
//   for(led=13; led<16; led++){
//    digitalWrite(PC+led, HIGH);
//    delay(1000);
//    digitalWrite(PC+led, LOW);
//    delay(1000);
  int bacaMerah = digitalRead(tombolMerah);
  int bacaKuning = digitalRead(tombolKuning);
  int bacaHijau = digitalRead(tombolHijau);
  
  if (bacaMerah ==1){
    digitalWrite(ledMerah, HIGH);
  }else{
    digitalWrite(ledMerah, LOW);
  }
  
  if (bacaKuning ==1){
    digitalWrite(ledKuning, HIGH);
  }else{
    digitalWrite(ledKuning, LOW);
  }
  
  if (bacaHijau ==1){
    digitalWrite(ledHijau, HIGH);
  }else{
    digitalWrite(ledHijau, LOW);
  }



  
//  digitalWrite(ledMerah,HIGH);
//  digitalWrite(ledKuning,HIGH);
//  digitalWrite(ledHijau,HIGH);
//  delay(1000);
//  digitalWrite(ledMerah,LOW);
//  digitalWrite(ledKuning,LOW);
//  digitalWrite(ledHijau,LOW);
//  delay(1000);

  
}
