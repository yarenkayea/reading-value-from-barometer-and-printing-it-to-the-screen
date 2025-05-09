#include "screen.h"

// Ekranı başlatan kurucu fonksiyon
Screen::Screen()
  : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

bool Screen::begin() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    return false;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  return true;  // <-- EKSİKTİ
}

void Screen::showWelcome() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Ekran Hazir!");
  display.display();
}

void Screen::showBarometerData(const Barometer& baro) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("BMP180 SENSOR VERILERI");

  display.setCursor(0, 15);
  display.print("Sicaklik: ");
  display.print(baro.getTemperature(), 1);
  display.println(" C");

  display.setCursor(0, 30);
  display.print("Basinc: ");
  display.print(baro.getPressure(), 1);
  display.println(" hPa");

  display.display();
}
