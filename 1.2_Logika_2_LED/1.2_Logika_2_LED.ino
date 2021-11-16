int TombolR = 2;
int TombolY = 3;
int TombolG = 4;

int R = 5;
int Y = 6;
int G = 7;

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
  Serial.println();
  
  //Logika
  if(bacaTombolR==1){
    digitalWrite(R, HIGH);
    digitalWrite(Y, HIGH);
   }else{
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    } //Tombol R
    
//  if(bacaTombolY==1){digitalWrite(Y, HIGH);}else{digitalWrite(Y, LOW);} //Tombol Y
//  if(bacaTombolG==1){digitalWrite(G, HIGH);}else{digitalWrite(G, LOW);} //Tombol G

}
