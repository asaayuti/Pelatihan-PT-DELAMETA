//Inisialisasi
int ledr = PC13;
int ledy = PA2;
int ledg = PC15;
int ir = PA0; // Infrared aktif low, aktif kalau 0
int ldr = PA1; // pin ADC, kalau dipin ADC tidak di pinMode
int kunci = 0;

void setup() {
  //Deklarasi pin I/O
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);

  //Serial begin
  Serial.begin(9600);
}

void loop() {
  //Baca Data
  int bacair = digitalRead(ir);
  int bacaldr = analogRead(ldr);

  //Merubah Data
  //Sebelum dirubah datanya lihat dulu nilai maks dan min nya
  bacaldr = map(bacaldr,0,4095,0,255);

  //Serial Print
  Serial.print("Nilai IR: " + String(bacair));
  Serial.println(" || Nilai LDR: " + String(bacaldr));

  //Logika
  //Infrared menyalakan led merah
//  if(bacair==0){
//    digitalWrite(ledr, HIGH);
//  }else{
//    digitalWrite(ledr, LOW);
//  }

//  LDR menyalakan lampu kuning
  analogWrite(ledy, bacaldr);
  

  //Infrared lock menyalakan lamput hijau
  if(bacair==0 and kunci==0){
    digitalWrite(ledr, HIGH);
    kunci = 1;
    delay(500); // untuk mengurangi noise
  }else if(bacair==0 and kunci==1){
    digitalWrite(ledr, LOW);
    kunci = 0;
    delay(500);
  }
}
