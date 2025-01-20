#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte S1[8] = {
  0b00000, 
  0b00000, 
  0b11011, 
  0b11111, 
  0b01110, 
  0b00100, 
  0b00000, 
  0b00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, S1);
  lcd.clear();
}

void loop() {
  // First checkerboard pattern
  lcd.clear();
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 16; col++) {
      if ((row + col) % 2 == 0) { // First pattern
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
  }
  delay(500); // Wait for half a second

  // Second checkerboard pattern (inverted)
  lcd.clear();
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 16; col++) {
      if ((row + col) % 2 == 1) { // Inverted pattern
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
  }
  delay(700); // Wait again before repeating
}
