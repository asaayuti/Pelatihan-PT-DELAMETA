#include <OneWire.h>
#include <DallasTemperature.h>

int sensorSuhu = 2;
int buzzer     = 3;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
  pinMode (buzzer, OUTPUT);
}

void loop() {
  // Baca Sensor
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0);

  // Print to Serail
  Serial.print("Suhu :" + String(bacaSuhu) + " C");
  Serial.println();

  if(bacaSuhu != DEVICE_DISCONNECTED_C)
  {
  Serial.print("Data suhu yang terbaca pada bus 1 (index 0): ");
  Serial.println(bacaSuhu);
  }
  else
  {
  Serial.println("Error: sensor pada index 0 tidak ditemukan!");
  }
  
  if(bacaSuhu >= 31){
    digitalWrite(buzzer, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
    }
   
}
