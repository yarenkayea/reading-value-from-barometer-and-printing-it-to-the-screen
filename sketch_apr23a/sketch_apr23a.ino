#include "barometer.h"
#include "screen.h"

Barometer baro;
Screen screen;

void setup() {
  Serial.begin(9600);

  if (!screen.begin()) {
    Serial.println("OLED ekran başlatılamadı!");
    while (1);
  }

  screen.showWelcome();
  delay(1000);

  if (!baro.begin()) {
    Serial.println("BMP180 bulunamadı!");
    while (1);
  }
}

void loop() {
  baro.update();
  screen.showBarometerData(baro);

  Serial.print("Sicaklik: ");
  Serial.print(baro.getTemperature());
  Serial.print(" °C, Basinc: ");
  Serial.print(baro.getPressure());
  Serial.println(" hPa");

  delay(3000);
}
