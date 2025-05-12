#include <SPI.h>
#include <Adafruit_PN532.h>

#define LED_PIN_AUTHORIZED 13
#define LED_PIN_UNAUTHORIZED 8

#define PN532_SCK (2)
#define PN532_MOSI (3)
#define PN532_SS (4)
#define PN532_MISO (5)

#define PN532_IRQ (2)
#define PN532_RESET (3)

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

#define AUTHORIZED_UID "73344e95"

void setup(void) {
  Serial.begin(38400);
  Serial.println("Hello!");

  pinMode(LED_PIN_AUTHORIZED, OUTPUT);
  pinMode(LED_PIN_UNAUTHORIZED, OUTPUT);

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1);
  }

  nfc.SAMConfig();
  Serial.println("Waiting for an NFC card...");
}

void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    Serial.println("Found an NFC card!");

    String uidString = "";
    for (uint8_t i = 0; i < uidLength; i++) {
      uidString += String(uid[i], HEX);
    }

    Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("UID Value: ");
    Serial.println(uidString);
    
    if (uidString == AUTHORIZED_UID) {
      digitalWrite(LED_PIN_AUTHORIZED, HIGH); 
      delay(1000); // tempo do LED
      digitalWrite(LED_PIN_AUTHORIZED, LOW); 
    } else {
      digitalWrite(LED_PIN_UNAUTHORIZED, HIGH); 
      delay(1000); // tempo do LED
      digitalWrite(LED_PIN_UNAUTHORIZED, LOW); 
    }
    delay(1000);
  }
}
