// 33 -  maxPh         -ap
// 34 -  minPh         -ip


void waterPh() {                // Until now this function reads ph and
     byte  i = 0;                       // reports alarm if ph too low or too high
     unsigned long  sum = 0;
     long reading = 0;

     while (i <= 20) {            // Read the sensor
      reading = analogRead(phPin);
      sum = sum + reading;
      delay(10);
      i++;
     }

     byte average = sum / i;

     //Converting to mV reading and then to pH
     float mvReading = average * Vs / 1024;
     //phValue=mvReading*K_PH;
     float mvReading_7 = 2.1191406250;  
     float mvReading_4 = 2.4365234375;
     float Healthy1_mv = 1.96;
     float offset = Healthy1_mv - mvReading_7;
     float Slope = 3 / (Healthy1_mv - mvReading_4 - offset);
     phValue = (7 - ((mvReading_7 - mvReading) * Slope));
     
   /*  lcd.clear();
     lcd.print(F("Slope :   "));
     lcd.print(Slope, DEC);
     delay(1500);
     lcd.clear();
     lcd.print(F("PH OK :   "));
     lcd.print(phValue, DEC);
     delay(500);
  */   
}
