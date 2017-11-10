#include "RelayControl.h"
#include "Arduino.h"

const int Relay_Power = 8;
const int Relay_Menu = 9;//10;
const int Relay_Auto = 12;//11;
const int Relay_Up = 10;//12;
const int Relay_Dn = 11;//8;
const int delay_time = 200;
const int delayP_time = 400;

RelayControl::RelayControl()
{
}

void RelayControl::initKey(){
  pinMode(Relay_Power, OUTPUT);
  pinMode(Relay_Menu, OUTPUT);
  pinMode(Relay_Auto, OUTPUT);  
  pinMode(Relay_Up, OUTPUT);
  pinMode(Relay_Dn, OUTPUT);  
  digitalWrite( Relay_Power, HIGH);            
  digitalWrite( Relay_Menu, HIGH);                       
  digitalWrite( Relay_Auto, HIGH);            
  digitalWrite( Relay_Dn, HIGH);                       
  digitalWrite( Relay_Up, HIGH);              
}

void RelayControl::MenuKey(){
     digitalWrite( Relay_Menu, LOW); 
     delay(delay_time);
     digitalWrite( Relay_Menu, HIGH);              
}

void RelayControl::PowerKey(){
     digitalWrite( Relay_Power, LOW); 
     delay(delayP_time);
     digitalWrite( Relay_Power, HIGH);              
}

void RelayControl::AutoKey(){
   digitalWrite( Relay_Auto, LOW); 
   delay(delay_time);
   digitalWrite( Relay_Auto, HIGH);            
}

void RelayControl::UpKey(){
   digitalWrite( Relay_Up, LOW); 
   delay(delay_time);
   digitalWrite( Relay_Up, HIGH);              
}

void RelayControl::DnKey(){
   digitalWrite( Relay_Dn, LOW); 
   delay(delay_time);
   digitalWrite( Relay_Dn, HIGH);              
}

void RelayControl::test0(Test_value *value){  
   if(value->duration_relay > value->times){
     if(value->index == '1')
        value->times = random(3000,20000);
     else
        value->times = 12000;
     switch(value->steptest){
       case 0: PowerKey(); break;
       case 1: PowerKey(); break;
       default: break;       
     }
     if(++value->steptest > 1){
          value->steptest = 0;
          value->looptime++;
          Serial.print("looptime =");
          Serial.println(value->looptime);          
     }
     value->startTime_relay = millis();     
   }
   value->duration_relay = millis() - value->startTime_relay;       
}

void RelayControl::test1(Test_value *value){
   if(value->duration_relay > value->times){
     int max_steptest = 5;
     int div = 5;     
     if(value->index == '1'){
        max_steptest = 6;
     }     
     value->times = 1500; 
     switch(value->steptest){
       case 0: AutoKey(); break;
       case 1: AutoKey(); break;              
       case 2: MenuKey(); break;
       case 3: for(int i=0;i<random(1,5);i++) {AutoKey(); delay(value->times);} break;       
       case 4: MenuKey(); break;       
       case 5: value->times = 15000; break;              
       case 6: if(value->looptime%div == 0){PowerKey(); delay(20000); PowerKey();value->times = 20000;}break;
       default: break;       
     }
     if(++value->steptest > max_steptest){
          value->steptest = 0;
          value->looptime++;
          Serial.print("looptime =");
          Serial.println(value->looptime);          
     }
     value->startTime_relay = millis();     
   }
   value->duration_relay = millis() - value->startTime_relay;         
}

void RelayControl::test2(Test_value *value){
   if(value->duration_relay > value->times){
     int ranValmax = 20,ranValmin = 2;          
     value->times = 1500;
     switch(value->steptest){
       case 0: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey();  break;       
       case 1: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey();  break;
       case 2: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey();  break;       
       case 3: AutoKey(); break;       
       case 4: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey();  break;       
       case 5: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey();  break;
       case 6: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey();  break;       
       case 7: AutoKey(); break;       
       default: break;       
     }
     if(++value->steptest > 7){
          value->steptest = 0; 
          value->looptime++;
          Serial.print("looptime =");
          Serial.println(value->looptime);
     }    
     value->startTime_relay = millis();     
   }
   value->duration_relay = millis() - value->startTime_relay;           
}

void RelayControl::test3(Test_value *value){
   if(value->duration_relay > value->times){
     int ranValmax = 20,ranValmin = 2;     
     value->times = 1500;
     switch(value->steptest){
       case 0: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey();  break;       
       case 1: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey();  break;
       case 2: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey();  break;       
       case 3: AutoKey(); break;       
       case 4: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey();  break;       
       case 5: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey();  break;
       case 6: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey();  break;       
       case 7: AutoKey(); break;       
       case 8: AutoKey(); break;
       case 9: AutoKey(); break;
       case 10: MenuKey();break;
       case 11: value->times = 8000; break;                      
       default: break;       
     }
     if(++value->steptest > 11){
          value->steptest = 0; 
          value->looptime++;
          Serial.print("looptime =");
          Serial.println(value->looptime);
     }    
     value->startTime_relay = millis();     
   }
   value->duration_relay = millis() - value->startTime_relay;             
}

void RelayControl::test5(Test_value *value){
   if(value->duration_relay > value->times){  
     int max_steptest = 7;
     value->times = 2000; 
     if(value->index == '1'){
       max_steptest = 9;
     }
     switch(value->steptest){
       case 0: MenuKey();  break;
       case 1: UpKey(); break;
       case 2: UpKey(); break;
       case 3: MenuKey(); break; 
       case 4: MenuKey(); break; 
       case 5: DnKey(); break;      
       case 6: MenuKey(); break;        
       case 7: value->times = 12000; break;               
       case 8: PowerKey(); value->times = 20000;break;
       case 9: PowerKey(); value->times = 20000;break;       
       default: break;       
     }
     Serial.print("value->steptest =");     
     Serial.println(value->steptest);                    
     if(++value->steptest > max_steptest){
          value->steptest = 0;
          value->looptime++;
          Serial.print("looptime =");
          Serial.println(value->looptime);          
     }
     value->startTime_relay = millis();     
   }
   value->duration_relay = millis() - value->startTime_relay;           
}

void RelayControl::test6(Test_value *value){
   if(value->duration_relay > value->times){  
     int ranValmax = 20,ranValmin = 2;
     int max_steptest = 34;
     int div = 3;
     if((value->index == '1')||(value->index == '3'))
         div = 2;     
     value->times = 1500;     
     if((value->index == '2')||(value->index == '3')){
       max_steptest = 36;
     }
     switch(value->steptest){
       case 0: MenuKey(); break;       
       case 1: MenuKey(); break;       
       case 2: MenuKey(); break;       
       case 3: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey(); break;       
       case 4: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey(); break;
       case 5: AutoKey(); break;                    
       case 6: DnKey(); break;       
       case 7: MenuKey(); break;              
       case 8: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey(); break;       
       case 9: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey(); break;
       case 10: AutoKey(); break;                    
       case 11: DnKey(); break;       
       case 12: MenuKey(); break;              
       case 13: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey(); break;       
       case 14: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey(); break;
       case 15: AutoKey(); break;                    
       case 16: DnKey(); break;       
       case 17: MenuKey(); break;              
       case 18: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey(); break;       
       case 19: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey(); break;
       case 20: AutoKey(); break;                    
       case 21: DnKey(); break;       
       case 22: MenuKey(); break;              
       case 23: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey(); break;       
       case 24: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey(); break;
       case 25: AutoKey(); break;                    
       case 26: DnKey(); break;       
       case 27: MenuKey(); break;              
       case 28: for(int i=0;i<random(ranValmin,ranValmax);i++) DnKey(); break;       
       case 29: for(int i=0;i<random(ranValmin,ranValmax);i++) UpKey(); break;
       case 30: AutoKey(); break;                    
       case 31: AutoKey(); break;                                   
       case 32: (value->change_state)?UpKey():DnKey();break;             
       case 33: AutoKey();break;                           
       case 34: break;                                  
       case 35: if(value->looptime % div == 0) PowerKey(); value->times = 15000; break;              
       case 36: if(value->looptime % div == 0) PowerKey(); value->times = 15000; break;              
       default: break;       
     }
     if(++value->steptest > max_steptest){
          value->steptest = 0;
          value->looptime++;
          Serial.print(" looptime =");          
          Serial.print(value->looptime);  
          Serial.print(" div =");                    
          Serial.println(div);            
          if(value->looptime % div == 0){
            if((value->index != '2')&&(value->index != '3'))            
                value->change_state = ~value->change_state;
          }     
     }
     value->startTime_relay = millis();     
   }
   value->duration_relay = millis() - value->startTime_relay;
}

