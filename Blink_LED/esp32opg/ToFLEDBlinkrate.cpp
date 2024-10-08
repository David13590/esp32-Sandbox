#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;

#define LED 17

    void setup(){
    Serial.begin(9600);
    Wire.begin();
    sensor.init();

    sensor.setTimeout(500);
    sensor.startContinuous();

    pinMode(LED, OUTPUT);

}

static int onTime = 100;
static int offTime = 10;
void blinkLed(){
    static int time = 0;
    if (time >= onTime){
        digitalWrite(LED, LOW);
    }
    
    if (time >= offTime+onTime){
        digitalWrite(LED, HIGH);
        time = 0;
    }
    time++;
}

void loop(){
    int distance = sensor.readRangeContinuousMillimeters();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("mm");
    if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
    
    blinkLed();
    
    Serial.println();
    delay(1);
}