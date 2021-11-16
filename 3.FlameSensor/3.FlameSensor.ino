//Inisialisasi


//int ldr    = A0;
int sensorflame = A1;
int ledR  = 2;
int ledY  = 3;
int ledG  = 4;
int buzzer    = 5;


void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  //Baca Data
  int bacaflame = analogRead(sensorflame);
      bacaflame = map(bacaflame,1023,23,0,100);
//  int bacaldr = analogRead(ldr);
//      bacaldr = map(bacaldr,0,1024,0,255);
      //0,1024 nilai ldr 0 sampai 1024
      //0,255 nilai yang diubah atau nilai led pwn 0-255
  //Print Serial
//  Serial.print("Nilai LDR : "+ String(bacaldr));
 
  Serial.print(" || Nilai sensor flame: " + String(bacaflame));
  Serial.println();   //Untuk Enter

  if(bacaflame <2){
    Serial.print("Aman");
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(buzzer, LOW);
  }else if(bacaflame >2 && bacaflame <=20){ 
    Serial.print("Warning Silahkan Periksa");
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }else{
    Serial.print("Waspada Harap Mengungsi");
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  
//  analogWrite(led, bacaldr);

//semakin terang semakin redup lednya
}
