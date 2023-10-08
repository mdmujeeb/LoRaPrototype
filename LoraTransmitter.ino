#include <SPI.h>
#include <LoRa.h>
 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
 
#define ss 15
#define rst 16
#define dio0 2
int counter = 0;
 
 
void setup() 
{
  Serial.begin(115200);
 
 while (!Serial);
  Serial.println("LoRa Sender");
  LoRa.setPins(ss, rst, dio0);
  LoRa.setSyncWord(786);
    if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    delay(100);
    while (1);
  }
}
 
void loop() 
{
  Serial.print("Sending packet: ");
  Serial.println(counter);
 
  Serial.print("Pkt No: ");
  Serial.println(counter);
  
  // send packet
  LoRa.beginPacket();
  LoRa.print(F("Pkt No:"));
  LoRa.println(counter);
  
  LoRa.endPacket();
 
  counter++;
 
  delay(3000);
}
