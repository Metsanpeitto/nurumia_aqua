
void clockCheck () {
  // Serial.println("---RTC___Clock--");
  DateTime now = RTC.now();
 
  lcd.clear();
  lcd.print(F("Time    Date "));
  lcd.setCursor(0, 2);
  lcd.print(now.hour());
  lcd.setCursor(2, 2);
  lcd.print(":");
  lcd.setCursor(3, 2);
  lcd.print(now.minute());
  lcd.setCursor(6, 2);
  lcd.print(now.day());
  lcd.setCursor(8, 2);
  lcd.print("-");
  lcd.setCursor(9, 2);
  lcd.print(now.month());
  lcd.setCursor(11, 2);
  lcd.print("-");
  lcd.setCursor(12, 2);
  lcd.print(now.year());
  delay(1000);
  
}
