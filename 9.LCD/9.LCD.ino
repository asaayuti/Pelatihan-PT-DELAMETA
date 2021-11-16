#include<LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  lcd.begin();
}

void loop(){
  //Program yang akan dijalankan berulang-ulang
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  lcd.setCursor(2,1);
  lcd.print("AHMAD SAYUTI");
  delay(1000);

  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  lcd.setCursor(2,1);
  lcd.print("DSFGK;F");
  delay(1000);
  
//  lcd.autoscroll();  
//  lcd.noAutoscroll();
//  lcd.clear();
}
