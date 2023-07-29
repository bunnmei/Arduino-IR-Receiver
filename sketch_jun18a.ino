#include <IRremote.hpp>

bool isLedOn = false;

void setup() {
  Serial.begin(9600);  
  // delay(500);
  pinMode(15, OUTPUT);
  IrReceiver.begin(8, true);
}

void loop() {
  if (IrReceiver.decode()){
    IrReceiver.printIRResultShort(&Serial);
    if(IrReceiver.decodedIRData.decodedRawData == 0xF30CFF00) {
      Serial.println("1");
      isLedOn = true;
    }else if(IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) {
      isLedOn = false;
    }
    IrReceiver.resume();
  }

  if(isLedOn){
    digitalWrite(15, HIGH);
  } else {
    digitalWrite(15, LOW);
  }
  // Serial.println(thermocouple.readCelsius());

  // digitalWrite(7, HIGH);
  // delay(1000);
  // digitalWrite(7, LOW);
  // delay(1000);
}
