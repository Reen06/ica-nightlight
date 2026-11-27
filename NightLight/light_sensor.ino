// light_sensor.ino - reads the photoresistor on LIGHT_SENSOR_PIN
// Returns 0 (dark) up to 1023 (bright).

int readLight() {
  // Average several readings to smooth out sensor noise.
  long total = 0;  // long, so a large sum cannot overflow an int
  for (int i = 0; i < SENSOR_SAMPLES; i++) {
    total += analogRead(LIGHT_SENSOR_PIN);
  }
  return total / SENSOR_SAMPLES;  // still 0 to 1023
}

const char* lightLabel(int light) {
  if (light < DARK_THRESHOLD) {
    return "dark";
  }
  return "bright";
}
