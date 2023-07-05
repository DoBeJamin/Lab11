/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab11/src/Lab11.ino"
#include "Particle.h"

#include "oled-wing-adafruit.h"

#include "LIS3DH.h"

void setup();
void loop();
void format_display ();
#line 7 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab11/src/Lab11.ino"
SYSTEM_THREAD(ENABLED);

SYSTEM_MODE(MANUAL);

const unsigned long PRINT_SAMPLE_PERIOD = 100;

LIS3DHSPI accel(SPI, D3, WKP);
OledWingAdafruit display;

unsigned long lastPrintSample = 0;


void setup(){
  display.setup();

  LIS3DHConfig config;
  config.setAccelMode(LIS3DH::RATE_100_HZ);

  accel.setup(config);

}

void loop(){

  display.loop();

  format_display ();

  
  LIS3DHSample sample;
  if (accel.getSample(sample))
  {
    display.println("X, Y, Z:");
    display.printf("%d,%d,%d", sample.x, sample.y, sample.z);
    display.display();
  }

}

void format_display () {
  //sets up basic formatting for when using the display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE); 
  display.setCursor(0,0);
}