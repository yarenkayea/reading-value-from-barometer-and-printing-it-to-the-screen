#include "barometer.h"

bool Barometer::begin() {
  return bmp.begin();
}

void Barometer::update(float irtifa) {
  sicaklik = bmp.readTemperature();
  basinc = bmp.readPressure() / 100.0;
  denizSeviyesiBasinci = bmp.readSealevelPressure(irtifa) / 100.0;
}

float Barometer::getTemperature() const {
  return sicaklik;
}

float Barometer::getPressure() const {
  return basinc;
}

float Barometer::getSeaLevelPressure() const {
  return denizSeviyesiBasinci;
}
