#include <SoftwareSerial.h>
#define NUMPIXELS 16

// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to

// How many NeoPixels are attached to the Arduino?


// Declare our NeoPixel strip objectAdafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);



#define LED_PIN 6  // Replace with the appropriate pin number
#define LED_COUNT 12  // Replace with the actual number of LEDs in your ring light

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(9600);  // Initialize the serial connection
}

void loop() {
  if (Serial.available()) {
    String emo = Serial.readString();  // Read the emotion data from the serial connection

    // Update the LED color based on the received emotion
    if (emo == "joy") {
      setLEDColor(pixels.Color(7, 130, 95, 3));  // mint color for joy
    } else if (emo == "sadness") {
      setLEDColor(pixels.Color(12, 50, 138,3));  // Blue color for sadness
    } else if (emo == "fear") {
      setLEDColor(pixels.Color(122,2, 242,3));  // Purple color for fear
    } else if (emo == "anger") {
      setLEDColor(pixels.Color(242, 2, 2,3));  // Red color for anger
    }
  }
}

void setLEDColor(uint32_t color) {
  for (int i = 0; i < LED_COUNT; i++) {
    pixels.setPixelColor(i, color);
  }
  pixels.show();
}
