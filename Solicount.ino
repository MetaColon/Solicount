#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 21, 4);

const int buttonPlus = 2;
const int buttonMinus = 3;

int count = 0;

const int max = 130;

void print() {
  lcd.clear();
  lcd.print("Willkommen!         Besucher*innen: ");
  lcd.print(count);
  if (count > max) {
    int pad = 4 - (int) floorf(log10(count));
    for (int i = 0; i < pad + 19; i++)
      lcd.print(" ");
    lcd.print("Zu viel Soli!!!");
  }
}

void setup() {
  pinMode(buttonPlus, OUTPUT);
  pinMode(buttonMinus, OUTPUT);

  lcd.begin();
  lcd.backlight();
  print();
}

void loop() {
  if (digitalRead(buttonPlus)) {
    count++;
    print();
    delay(100);
  }
  if (digitalRead(buttonMinus)) {
    count--;
    print();
    delay(100);
  }
}
