void setup() {
  Serial.begin(9600);
  for (int i=9; i<=11; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  for(float a=0; a<255; a++){
    analogWrite(9,a);
    analogWrite(10,a);
    analogWrite(11,a);
//    float volt=map(a,0,255,0,5); //Konversi Nilai PWM ke volt dari 0-255 menjadi 0-5
    float volt = (5.0/255.0);
    float hasil = a * volt;
   
    Serial.println(hasil); // Menampilkan Hasil
    delay(10);
  }
  for(int a=255; a>=0; a--){
    analogWrite(9,a); // pin 3 lampu kuning
    analogWrite(10,a); // pin 3 lampu kuning
    analogWrite(11,a); // pin 3 lampu kuning
    float volt = (5.0/255.0);
    float hasil = a * volt;
//    Serial.print("volt :");
    Serial.println(hasil);
    delay(10);
  }
//  analogWrite(3,0);
//  delay(1000);
//  analogWrite(3,100);
//  delay(1000);
//  analogWrite(3,200);
//  delay(1000);
//  analogWrite(3,255);
//  delay(1000);
}
