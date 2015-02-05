#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  
  lcd.print("hello, Burke");
  delay(1000);
  
  printElipsis();
}

void loop() {  
  printLines("Never gonna give", "you up", true);
  printLines("never gonna let", "you down", true);
  printLines("never gonna run", "around and", true);
  printLines("desert you", "", false);
  printLines("Never gonna make", "you cry", true);
  printLines("never gonna say", "goodbye", true);
  printLines("never gonna tell", "a lie", true);
  printLines("and hurt you", "", false);
  delay(10000);
}

void printElipsis() {
  int i;
  
  for (i = 0; i < 3; i++) {
    lcd.print(".");
    delay(500);
  }
}

void printLines(String firstLine, String secondLine, boolean elipsis) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstLine);
  lcd.setCursor(0, 1);
  lcd.print(secondLine);
  
  if (elipsis)
    printElipsis();
  
  delay(2000);
}
