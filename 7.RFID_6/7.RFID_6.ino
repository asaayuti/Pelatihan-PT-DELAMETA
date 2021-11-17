#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
//pake motor
String uidString;
int outServo = PA2;
int buzzer = PB0;
int infrared = PA4;
int kunci = 0;
#define SS_PIN PA0
#define RST_PIN PA1
MFRC522 mfrc522(SS_PIN, RST_PIN);   //Create MFRC522 instance
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo;

void setup(){
  //Dekalarasi Pin I/O
  pinMode(buzzer, OUTPUT);
  pinMode(infrared, INPUT);
  
  Serial.begin(9600);
  SPI.begin();  //Initiate SPI bus
  lcd.begin();
  mfrc522.PCD_Init();
  myservo.attach(outServo);
  bunyibuzzeroke();
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0);
  lcd.print("Tempelkan Kartu!");
  Serial.println("Tempelkan Kartu!");
  delay(1000);
}

void loop(){
  //Baca Data
  int bacaIR= digitalRead(infrared);

  //Logika
  if(mfrc522.PICC_IsNewCardPresent() and kunci==0){
    readRFID();
    Serial.print("Tag UID: " + String(uidString));
  if(uidString=="2A-A5-B7-15"){
    bunyibuzzeroke();
//    lcd.clear(); //Untuk Menghapus karakter pada LCD
//    lcd.setCursor(0,0);
//    lcd.print("Tempelkan Kartu!");
//    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BERHASIL");
    Serial.println("BERHASIL");
    delay(1000);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("AHMAD");
    Serial.println("AHMAD");
    lcd.setCursor(0,1);
    lcd.print("Silahkan Masuk!");
    Serial.println("Silahkan Masuk!");
    myservo.write(180);
    delay(1000);
    kunci = 1;
  }else if(uidString=="1A-C-E9-80" && kunci==0){
    bunyibuzzeroke();
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("SAYUTI");
    Serial.println("SAYUTI");
    lcd.setCursor(0,1);
    lcd.print("Silahkan Masuk");
    Serial.println("Silahkan Masuk!");
    myservo.write(180);
    delay(1000);
    kunci=1;
  }else{
    bunyibuzzergagal();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GAGAL");
    Serial.println("GAGAL");
    delay(1000);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0);
    lcd.print("Tempelkan Kartu!");
    Serial.println("Tempelkan Kartu!");
  }
  }
 
  if (bacaIR==0 and kunci==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Palang Tertutup");
    delay(1000);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0);
    lcd.print("Tempelkan Kartu!");
    Serial.print("Tempelkan Kartu!");
//    lcd.clear();
    delay(1000);
    bunyibuzzergagal();
    kunci= 0;
    myservo.write(90); //0-180
    delay(1000);
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
  delay(1000);
  digitalWrite(buzzer, LOW);
}
