//adds the necessary libraries
#include <MFRC522.h> 
#include <SPI.h>


//defines the functions
#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 5 

MFRC522 mfrc522(SS_PIN, RST_PIN); //initialises an instance of the MFRC522 RFID reader library with the specified pins

unsigned long alarmDuration = 10000;  //amount of milliseconds the alarm takes - 10 seconds
unsigned long alarmStartTime;  //stores the starting time of the alarm
void setup() {
  Serial.begin(9600); //initialises the serial communication
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(BUZZER_PIN, OUTPUT);  
//all of these initialise different connections used for the program
}

void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH); 
//creates a function that activates the buzzer by setting it to high
}

void deactivateBuzzer() {
  digitalWrite(BUZZER_PIN, LOW);  
//creates a function that deactivates the buzzer by setting it to low
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
//if the tag is detected the buzzer is deactivated 
  }
}
