int TombolR = 2;
int TombolY = 3;
int TombolG = 4;
int R = 5;
int Y = 6;
int G = 7;
int kunci1, kunci2, kunci3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TombolR,INPUT);
  pinMode(TombolY,INPUT);
  pinMode(TombolG,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  int bacaTombolR = digitalRead(TombolR);
  int bacaTombolY = digitalRead(TombolY);
  int bacaTombolG = digitalRead(TombolG);
  
  Serial.print("Kondisi Tombol R: " + String(bacaTombolR));
  Serial.print(" | Kondisi Tombol Y: " + String(bacaTombolY));
  Serial.print(" | Kondisi Tombol G: " + String(bacaTombolG));
  Serial.print(" | " + String(kunci1));
  Serial.println();
  
  //Logika
  if(bacaTombolR==1 and kunci1==0){
    digitalWrite(R, HIGH);
    kunci1 = 1;
//    delay(500);
  }else if(bacaTombolR==1 and kunci1==1){
    digitalWrite(R, LOW);
    kunci1 = 0;
//    delay(500);
  }

  if(bacaTombolY==1 and kunci2==0){
    digitalWrite(Y, HIGH);
    kunci2 = 1;
//    delay(500);
  }else if(bacaTombolY==1 and kunci2==1){
    digitalWrite(Y, LOW);
    kunci2 = 0;
//    delay(500);
    }

  if(bacaTombolG==1 and kunci3==0){
    digitalWrite(G, HIGH);
    kunci3 = 1;
//    delay(500);
  }else if(bacaTombolG==1 and kunci3==1){
    digitalWrite(G, LOW);
    kunci3 = 0;
//    delay(500);
  }

}
