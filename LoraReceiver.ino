#include <SPI.h>
#include <LoRa.h>
 
#define ss 15
#define rst 16
#define dio0 4
 
void setup() {
  Serial.begin(115200);
  while (!Serial);3+-
 
  Serial.println("LoRa Receiver Callback");
 
  LoRa.setPins(ss, rst, dio0);
  LoRa.setSyncWord(786);
 
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
 
  // register the receive callback
  LoRa.onReceive(onReceive);
 
  // put the radio into receive mode
  LoRa.receive();
}
 
void loop() {
  // do nothing
}
 
void onReceive(int packetSize) {
  // received a packet
  Serial.print("Received packet '");
 
  // read packet
  for (int i = 0; i < packetSize; i++) {
    Serial.print((char)LoRa.read());
  }
 
  // print RSSI of packet
  Serial.print("' with RSSI ");
  Serial.println(LoRa.packetRssi());
}
