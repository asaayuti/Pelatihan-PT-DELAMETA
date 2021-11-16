//Inisialisasi
int ledr = PA0;
int ledy = PA1;
int ledg = PA2;
int ir = PA3;
int ldr = PA4;
int kunci = 0;

void setup() {
  // Deklarasi pin I/O
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);

  //Serial begin
  Serial.begin(9600);
}

void loop() {
  // Baca Data
  int bacair = digitalRead(ir);
  int bacaldr = analogRead(ldr);

  //Merubah data
  bacaldr = map(bacaldr,0,4095,255,0);
  
  //Serial print
  Serial.print("Nilai IR: " + String(bacair));
  Serial.println(" || Nilai LDR: " + String(bacaldr));
  Serial.println(kunci); 

  //Logika
  if(bacair==0 and kunci==0){
    kunci=1;
    delay(500);
  }else if(bacair==0 and kunci==1){
    digitalWrite(ledg, LOW);
    digitalWrite(ledy, LOW);
    digitalWrite(ledr, LOW);
    kunci=0;
    delay(500);
  }

  if(bacaldr>=200 and kunci==1){
      digitalWrite(ledg, HIGH);
      digitalWrite(ledy, LOW);
      digitalWrite(ledr, LOW);
    }else if(bacaldr>=100 and bacaldr<200  and kunci==1){
      digitalWrite(ledg, LOW);
      digitalWrite(ledy, HIGH);
      digitalWrite(ledr, LOW);
    }else if(kunci==1){
      digitalWrite(ledg, LOW);
      digitalWrite(ledy, LOW);
      digitalWrite(ledr, HIGH);
    }

}
