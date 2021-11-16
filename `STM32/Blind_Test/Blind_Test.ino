//Inisialisasi
int ledR = PC13;
int ledY = PC14;
int ledG = PC15;
int tombolR = PA0;
int tombolY = PA1;
int tombolG = PA2;
int kunci = 0;

void setup() {
  //Deklarasi pin output dan input
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(tombolR, INPUT);
  pinMode(tombolY, INPUT);
  pinMode(tombolG, INPUT);
  

}

void loop() {
  //Baca Data
  int bacaR = digitalRead(tombolR);
  int bacaY = digitalRead(tombolY);
  int bacaG = digitalRead(tombolG);

  //Print Serial
  Serial.print("Nilai Tombol G: " + String(bacaG));
  Serial.print(" || Nilai Tombol Y: " + String(bacaY));
  Serial.print(" || Nilai Tombol R: " + String(bacaR));
  Serial.println();

  //Logika
  if(bacaR == 1 and kunci == 0) {
    digitalWrite(ledR, HIGH);
    kunci = 1;
    delay(500);
  }else if(bacaR == 1 and kunci ==1){
    digitalWrite(ledR, LOW);
    kunci = 0;
    delay(500);
  }

  if(bacaY == 1 and kunci == 0) {
    digitalWrite(ledY, HIGH);
    kunci = 1;
    delay(500);
  }else if(bacaY == 1 and kunci ==1){
    digitalWrite(ledY, LOW);
    kunci = 0;
    delay(500);
  }
  
  if(bacaG == 1 and kunci == 0) {
    digitalWrite(ledG, HIGH);
    kunci = 1;
    delay(500);
  }else if(bacaG == 1 and kunci ==1){
    digitalWrite(ledG, LOW);
    kunci = 0;
    delay(500);
  }
  
}
