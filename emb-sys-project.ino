
#include <NewPing.h>
#include <Servo.h> 
#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 30 // Maximum distance to ping in cm

#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    100

CRGB leds[NUM_LEDS];
 


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
Serial.begin(9600); // initialize the serial port:
FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {
 
  delay(50);
  DistanceToSerial();
  LED();
 
 
}
int DistanceToSerial() {
  int cm = sonar.ping_cm();
  delay(1000);
 
  Serial.print("The object is ");
  Serial.print(cm);
  Serial.println(" cm away");

}

int LED(){
int distance = sonar.ping_cm();
if(distance < 5 ){
    

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);

    for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(10);
  }
  }
  else if(distance <= 10){
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);

    for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(10);
  }
  }
  else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);

 for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 0, 128, 0);
    FastLED.show();
    delay(10);
    
  }

}
}
  // we will have 3 or 4 zones of distance 
  // the zones will be the max distance devided by the number of zones
  // when the distace comes in to a zone print it on the matrix 
  // or use leds red, orange, green to show diffrent zones 

  
