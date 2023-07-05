#include "Particle.h"
#include "oled-wing-adafruit.h"
#include "LIS3DH.h"

SYSTEM_THREAD(ENABLED);

SYSTEM_MODE(MANUAL);

LIS3DHSPI accel(SPI, D3, WKP);
OledWingAdafruit display;

void setup(){

  display.setup();

  //configure accelerometer
  LIS3DHConfig config;
  config.setAccelMode(LIS3DH::RATE_100_HZ);
  accel.setup(config);

}

void loop(){
  //maintain display
  display.loop();

  format_display ();

  //print accelerometer sample recieved
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