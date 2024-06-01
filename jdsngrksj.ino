#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 5 

MFRC522 mfrc522(SS_PIN, RST_PIN);

unsigned long alarmDuration = 10000;  
unsigned long alarmStartTime;  
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(BUZZER_PIN, OUTPUT);  
}

void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH); 
}

void deactivateBuzzer() {
  digitalWrite(BUZZER_PIN, LOW);  
}

void loop() {
  unsigned long currentTime = millis();  

  if (currentTime - alarmStartTime >= alarmDuration) {
    activateBuzzer();  
  }

  
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("RFID tag detected!");
    deactivateBuzzer();  
    delay(1000);  
  }
}