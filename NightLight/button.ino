// button.ino - reads the pushbutton on BUTTON_PIN
// The button connects the pin to GND, so a press reads LOW.

#include <Arduino.h>

// Should return true once for each press of the button.
bool buttonPressed() {
  // TODO Task 3 (Developer C): debounce, and detect one press (not a held button).
  static bool lastButtonState = HIGH;
  static unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 50;

  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentButtonState == LOW && lastButtonState == HIGH) {
      return true;
    }
  }

  lastButtonState = currentButtonState;
  return false;
}
