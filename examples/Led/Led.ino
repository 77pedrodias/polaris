/**
 * @file Led.ino
 * @brief Full example of the Led class from the Polaris library.
 * 
 * Demonstrates the full functionality of the Led class, including
 * on/off control, toggle, non-blocking blinking, and status reading.
 * 
 * @version 1.0
 * @date 2025-05-30
 * @author Pedro Dias
 * @copyright Public Domain
 * 
 * @details
 * ## Circuit:
 * - LED connected to digital pin 3 through a 330 ohm resistor.
 * - The other side of the LED connected to ground.
 * 
 * Polaris Library Repository:
 * https://github.com/77pedrodias/polaris
 */

#include <Led.h>

Led led(3);

void setup() {
  Serial.begin(9600);

  led.begin();

  // Turn LED ON for 1 second
  led.on();
  Serial.println("LED is ON");
  delay(1000);

  // Turn LED OFF for 1 second
  led.off();
  Serial.println("LED is OFF");
  delay(1000);

  // Toggle LED (turns ON)
  led.toggle();
  Serial.println("LED toggled (should be ON)");
  delay(1000);

  // Toggle LED (turns OFF)
  led.toggle();
  Serial.println("LED toggled (should be OFF)");
  delay(1000);

  // Start blinking every 500ms
  led.startBlink(500);
  Serial.println("Blink started (500ms)");
}

void loop() {
  // Always call update to handle blinking
  led.update();

  // Example of reading status every 2 seconds
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 2000) {
    lastPrint = millis();

    Serial.print("Blink count: ");
    Serial.println(led.getBlinkCount());

    Serial.print("Is blinking: ");
    Serial.println(led.isBlinking() ? "YES" : "NO");

    Serial.print("Is ON: ");
    Serial.println(led.isOn() ? "YES" : "NO");
  }

  // Example: stop blinking after 10 toggles
  if (led.getBlinkCount() >= 10 && led.isBlinking()) {
    led.stopBlink();
    Serial.println("Blink stopped after 10 toggles.");
    led.off();
  }
}