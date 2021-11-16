int R=2;
int Y=3;
int G=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
//pin 13 = LED_BUILTIN arduino uno
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(R,HIGH);
digitalWrite(Y,HIGH);
digitalWrite(G,HIGH);
delay(1000);
digitalWrite(R,LOW);
digitalWrite(Y,LOW);
digitalWrite(G,LOW);
delay(100);
}
