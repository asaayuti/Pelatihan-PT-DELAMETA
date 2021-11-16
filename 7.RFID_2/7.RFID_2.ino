#include <SPI.h>
#include <MFRC522.h>

String uidString;

int buzzer = 6;
int infrared = 2;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   //Create MFRC522 instance

void setup(){
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  SPI.begin();  //Initiate SPI bus
  mfrc522.PCD_Init();
  bunyibuzzeroke();
  Serial.println("Tempelkan Kartu!");
}

void loop(){
  //Baca Data
  if(mfrc522.PICC_IsNewCardPresent()){
    readRFID();
    Serial.print("Tag UID: " + String(uidString));
  if(uidString=="2A-A5-B7-15"){
    bunyibuzzeroke();
    Serial.println(" BERHASIL!");
    delay(1000);
    Serial.println("Silahkan Masuk!");
  }else if(uidString=="1A-C-E9-80"){
    bunyibuzzeroke();
    Serial.println("BERHASIL!");
    delay(1000);
    Serial.println("Silahkan Masuk!");
  }else{
    Serial.println(" GAGAL");
    bunyibuzzergagal();
  }
}
}

void readRFID() {
  mfrc522.PICC_ReadCardSerial();
  //Pembatas bisa dirubah sesuai keinginan, disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}

void bunyibuzzeroke(){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100); 
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100); 
}

void bunyibuzzergagal(){
  digitalWrite(buzzer, HIGH);
  delay(2000);
  digitalWrite(buzzer, LOW);
}
