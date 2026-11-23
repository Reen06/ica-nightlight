// logger.ino - prints status messages to the Serial Monitor (9600 baud)

const char* modeName(Mode mode) {
  switch (mode) {
    case MODE_OFF:  return "OFF";
    case MODE_AUTO: return "AUTO";
    case MODE_ON:   return "ON";
  }
  return "UNKNOWN";
}

void logStatus(int light) {
  static unsigned long lastLog = 0;
  unsigned long now = millis();
  if (now - lastLog < LOG_INTERVAL_MS) {
    return;
  }
  lastLog = now;

  Serial.print("Mode: ");
  Serial.print(modeName(currentMode));
  Serial.print(" | Light: ");
  Serial.print(light);
  Serial.print(" | Room: ");
  Serial.print(lightLabel(light));
  Serial.print(" | LED: ");
  Serial.println(ledBrightness);
}

// TODO Task 6 (Developer B): add logBanner() below this line.
