#ifndef SCREEN_H
#define SCREEN_H

#include "barometer.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

class Screen {
  private:
    Adafruit_SSD1306 display;

  public:
    Screen(); 
    bool begin();
    void showWelcome();
    void showBarometerData(const Barometer& baro);
};

void init_screen(); 

#endif
