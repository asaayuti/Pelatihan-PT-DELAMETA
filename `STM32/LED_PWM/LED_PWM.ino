//Inisialisasi
int led = PA3; // pin PWM
int ldr = PA2; // pin PWM
void setup() {
  //Deklarasi input output
  pinMode(led, OUTPUT);
  //Serial begin
  Serial.begin(9600);

}

void loop() {
  //Baca Data
  int bacaldr = analogRead(ldr);
  
  //Serial Print
  Serial.print("Nilai LDR: ");
  Serial.println(bacaldr);
  Serial.println();

  analogWrite(led, ldr );
 

}
