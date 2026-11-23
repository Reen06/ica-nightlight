// light_sensor.ino - reads the photoresistor on LIGHT_SENSOR_PIN
// Returns 0 (dark) up to 1023 (bright).

int readLight() {
  // TODO Task 1 (Developer A): average SENSOR_SAMPLES readings.
  return analogRead(LIGHT_SENSOR_PIN);
}

const char* lightLabel(int light) {
  if (light < DARK_THRESHOLD) {
    return "dark";
  }
  return "bright";
}
