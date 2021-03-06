/*
  NeoPixel RGBW fade

  This sketch  fades one color of a neoPixel device.

  Uses Adafruit's NeoPixel library: https://github.com/adafruit/Adafruit_NeoPixel

  created 29 Oct 2017
  by Tom Igoe
*/

#include <Adafruit_NeoPixel.h>
const int neoPixelPin = 5;   // control pin
const int pixelCount = 7;    // number of pixels

int red = 0xFF;     // try fixing the other colors
int green = 0x00;   // at levels other than 0
int blue = 0x00;    // to see how it affects the fade
int white = 0x00;
int change = 1;

// set up strip:
Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixelCount, neoPixelPin, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();    // initialize pixel strip
  strip.clear();    // turn all LEDs off
  strip.show();     // update strip
}

void loop() {
  // loop over all the pixels:
  for (int pixel = 0; pixel < pixelCount; pixel++) {
    strip.setPixelColor(pixel, red, green, blue, white);    // set the color for this pixel
    strip.show();   // update the strip
    delay(100);
  }

  // increment hue to fade from red (0) to reddish orange (15) and back:
  red = red + change;
  if (red < 0 || red > 100) {
    change = -change;
  }
}
