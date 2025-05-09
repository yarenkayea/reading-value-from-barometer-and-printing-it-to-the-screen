#ifndef BAROMETER_H
#define BAROMETER_H

#include <Wire.h>
#include <Adafruit_BMP085.h>

class Barometer {
  private:
    Adafruit_BMP085 bmp;
    float sicaklik;
    float basinc;
    float denizSeviyesiBasinci;

  public:
    bool begin();
    void update(float irtifa = 390); // verileri güncelle
    float getTemperature() const;
    float getPressure() const;
    float getSeaLevelPressure() const;
};

#endif
