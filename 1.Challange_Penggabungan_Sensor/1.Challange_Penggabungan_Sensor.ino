//Inisialisasi
int ldr    = A0;
int sensorflame = A1;
int ledR  = 3;
int buzzer    = 5;
int pir       = 6;

//int ledY  = 2;
//int ledG  = 4;
//tampilkan semua sensor pada serial monitor 
//bikin logika dari masing2 sensor 
//ldr untuk menyalakan lampu
//flame pakai buzzer

void setup() {
  Serial.begin(9600);
  pinMode(pir,    INPUT );
  pinMode(buzzer, OUTPUT);
  pinMode(ledR,   OUTPUT);
//  pinMode(ledY, OUTPUT);
//  pinMode(ledG, OUTPUT);
 
}

void loop() {
  //Baca Data
  int bacapir   = digitalRead(pir);
  int bacaflame = analogRead(sensorflame);
      bacaflame = map(bacaflame,1023,23,0,100); //1023 dari 2 pangkat 8
  int bacaldr   = analogRead(ldr);
      bacaldr   = map(bacaldr,0,1024,0,255);
      //0,1024 nilai ldr 0 sampai 1024
      //0,255 nilai yang diubah atau nilai led pwn 0-255
      
  //Print Serial
  Serial.print("Nilai LDR : "+ String(bacaldr));
  Serial.print(" || Nilai sensor pir: " + String(bacaflame));
  Serial.print(" || Nilai sensor flame: " + String(bacaflame));
  Serial.println();   //Untuk Enter

  analogWrite(ledR, bacaldr);

  if(bacaflame <20){
    digitalWrite(buzzer, LOW);
  }else{
    digitalWrite(buzzer, HIGH);
  }
}

//  }else if(bacaflame >2 && bacaflame <=20){ 
//    Serial.print("Warning Silahkan Periksa");
//    digitalWrite(ledY, HIGH);
//    digitalWrite(ledG, LOW);
//    digitalWrite(ledR, LOW);
//    digitalWrite(buzzer, HIGH);
//    delay(500);
//    digitalWrite(buzzer, LOW);
//    delay(500);}
//  }else{
//    digitalWrite(buzzer,LOW);
//    delay(100);
//    digitalWrite(buzzer, LOW);
//    delay(100);
//  }
  
//semakin terang semakin redup lednya
