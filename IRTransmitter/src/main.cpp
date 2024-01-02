#include <Arduino.h>
#include <IRremote.h>
#include <string>

#include "fan/Fan.h"

#define IR_RECEIVE_PIN           4
#define IR_SEND_PIN              9
#define TONE_PIN                10 // ADC2_0
#define APPLICATION_PIN         11




Fan fan;

void printState() {
  Serial.println("Fan State: ");
  Serial.printf("\t%s\n", fan.fanState().c_str());
}

void setup() {
  Serial.begin(115200);
  delay(200);

  Serial.println("\nDefault state of the remote");
  printState();
  Serial.println("\nSetting initial state for Fan");

  IrReceiver.begin(IR_RECEIVE_PIN,ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to receive IR signals of protocols: "));
  printActiveIRProtocols(&Serial);
}

void loop() {

  if(IrReceiver.decode()){
    Serial.println("Received IR code: Ox");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
      

    IrReceiver.resume();

  }
}