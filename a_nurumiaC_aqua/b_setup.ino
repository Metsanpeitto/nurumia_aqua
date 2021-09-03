/*                
 *                                                       ATTENTION !!!!!!!
 *     
 *     
 *     During development I use a sacrifice chip where I write continuosly,being conscius that it can 
 *   be written 100.000 times before start failing .             
 *   
 *       1 - For deployment use a new chip .  
 *       2 - Upload the code without comments.
 *       3 - In the programmer use the option to NOT erase the EEPROM and comment all the eeprom write in setup
 *       4 - Upload it for the last time and deploy
 */

void setup() {
 Serial.begin(115200);
  while (!Serial) continue;  
  Wire.begin();
  
  RTC.begin();
  //RTC.adjust(DateTime(2014, 1, 21, 2, 0, 0));
  RTC.adjust(DateTime(__DATE__, __TIME__));

  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16, 2); //Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light  

  lcd.clear();
  lcd.print("-----Works-----");
  delay(2000);

  clockCheck();                       
 
}
