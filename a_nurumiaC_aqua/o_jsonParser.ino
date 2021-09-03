   //char* jsonKeyAlarm[] = {"header", "lh", "ll", "ln", "lf", "ma", "mo", "ah", "ac", "am", "ad", "wh", "wc", "ph", "pl", "wd"};
   //char* jsonKeySetup[] = {"header", "df", "dv", "ov", "of", "wa", "wi", "pa", "pi", "aa", "ai", "ha", "hi"};
   //char* jsonKeyControl[] = {"header", "p", "vi", "vo", "l", "ah", "wh", "f"};
   
   // alarms
   //     0 lh              1  ll            2 ln         3  lf         4 ma        5 mo       6 ah    7 ac        
   //waterLevelTooHigh, waterLevelTooLow, lightOnNoOff, lightOffNoOn, motionStart, motionStop, airHot,airCold,


   //alarms2
   //    0 am    1 ad    2 wh       3 wc      4 ph    5 pl     6 wd 
   //  airMoist,airDry, waterHot, waterCold, phHigh, phLow, waterDetect;

// Save ramdom global booleans in this byte
// 0- flushing   1-firstcharacter  2- controlIn  3- setupIn  4- switcherManual
// byte randomBooleans = 0b00000000;

char* positiveOrNegative(byte number,char node){   
      char* result1 = "";
      
     if(node == 'a'){
        if(number <= 7){
         if(bitRead(alarms,number) == 1){
         result1 = "1";
        } else { 
               result1 = "0";
               }
      } else {
          number = number - 8;
         if(bitRead(alarms2,number) == 1){
         result1 = "1";
        } else { 
                result1 = "0";
               }        
       }       
     }
    
    if(node == 'c'){
     // lcd.clear();
     // lcd.print(number);
     // delay(1000);
     // lcd.clear();
     // lcd.print(bitRead(states,number),DEC );
     // delay(1000);
     bitRead(states,number) == 1 ?  result1 = "0": result1 = "1";
      
       if(bitRead(states,number) == 1){
         result1 = "0";
        } else { 
               result1 = "1";
               }
      }           
   //  lcd.clear();
   //   lcd.print(result1);
  //    delay(1000);
    return result1;
  }

   
void jsonParser(byte node) {    
     
      // We expect an Array as follows  {"header": "alarm",  "ll": "1", "lh";"1"}
      DynamicJsonBuffer jsonBuffer;
      JsonObject& object = jsonBuffer.createObject();

    if((char)node == 'a'){   
      object[F("header")] = F("alarm");
      delay(40);   
      object[F("lh")] = (char*)positiveOrNegative(0,node); 
      delay(40);     
      object[F("ll")] = (char*)positiveOrNegative(1,node);
      delay(40);
      object[F("ln")] = (char*)positiveOrNegative(2,node);
      delay(40);  
      object[F("lf")] = (char*)positiveOrNegative(3,node);
      delay(40);   
      object[F("ma")] = (char*)positiveOrNegative(4,node);
      delay(40); 
      object[F("mo")] = (char*)positiveOrNegative(5,node);
      delay(40);
      object[F("ah")] = (char*)positiveOrNegative(6,node);
      delay(40);
      object[F("ac")] = (char*)positiveOrNegative(7,node);
      delay(40);
      object[F("am")] = (char*)positiveOrNegative(8,node);
      delay(40);
      object[F("ad")] = (char*)positiveOrNegative(9,node);
      delay(40);
      object[F("wh")] = (char*)positiveOrNegative(10,node);
      delay(40);
      object[F("wc")] = (char*)positiveOrNegative(11,node);
      delay(40);
      object[F("ph")] = (char*)positiveOrNegative(12,node);
      delay(40);
      object[F("pl")] = (char*)positiveOrNegative(13,node);
      delay(40);
      object[F("wd")] = (char*)positiveOrNegative(14,node);     
      delay(40);                            
   }

    if((char)node == 'c'){     
      object[F("header")] = F("control");   
      object[F("p")]  = (char*)positiveOrNegative(0,node);      
      object[F("vi")] = (char*)positiveOrNegative(1,node);
      object[F("vo")] = (char*)positiveOrNegative(2,node); 
      object[F("l")]  = (char*)positiveOrNegative(3,node);
      object[F("ah")] = (char*)positiveOrNegative(4,node);
      object[F("wh")] = (char*)positiveOrNegative(5,node);
      object[F("f")]  = (char*)positiveOrNegative(6,node);  
    }    


      Serial.flush();   
      object.printTo(lcd); 
      object.printTo(Serial);
      Serial.print('\n');
      delay(1000);
      Serial.flush();
 
}




 
