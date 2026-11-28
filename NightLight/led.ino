// led.ino - controls the LED brightness (0 = off, 255 = full brightness)

int ledBrightness = 0;   // remembers the current brightness

void setLed(int brightness) {
  ledBrightness = constrain(brightness, 0, 255);
  analogWrite(LED_PIN, ledBrightness);
}
// test cmd and pull/push

// Moves the LED toward the target brightness.
void fadeTowards(int target) {
  // TODO Task 2 (Developer B): fade in small steps instead of jumping.
  
  // Increase or decrease ledBrightness by FADE_STEP until it reaches target.
  // Then call setLed() with the new value.

  if (ledBrightness < target) {
    ledBrightness = min(ledBrightness + FADE_STEP, target);
  } else if (ledBrightness > target) {
    ledBrightness = max(ledBrightness - FADE_STEP, target);
  }
  setLed(ledBrightness);

}

// TODO Task 7 (Developer C): add blinkLed() below this line.
