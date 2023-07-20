#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PulseWire = 0;
const int LED13 = 13;
int Threshold = 550;

PulseSensorPlayground pulseSensor;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

 pulseSensor.analogInput(PulseWire);
 pulseSensor.blinkOnPulse(LED13);
 pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()){
    Serial.println("We created Pulse Heart Object !");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 int myBPM = pulseSensor.getBeatsPerMinute();

 if (pulseSensor.sawStartOfBeat()){
  Serial.print("BPM: ");
  Serial.println(myBPM);
 }
 delay(20);
}
