#include "CommonColors.h"
#include "Color.h"
#include "RelayControl.h"
#include "Common.h"

Test_value value;  // 測試物件
char val;
char buffer[16];
char counter=0;
RelayControl rc;  // 產生Relay物件
Color cl; 
void setup()
{  
  rc.initKey();       //  初始化Relay的GPIO狀態
  Serial.begin(57600);                     // 開啟 Serial port, 通訊速率為 9600 bps
  Serial.println("setup");  
  Serial.println(clRed.getRed());
  Serial.println(cl.getRed());    
}
void loop()
{
  if(Serial.available()){
    val = Serial.read();
    buffer[counter] = val;    
    counter++;      
    if(counter > 3){    
             for(int i=0;i<counter;i++){
                  if((buffer[i] == 'A')&&(buffer[i+2] == 'F')&&(buffer[i+3] == 'F')){
                      switch(buffer[i+1]){
                     case 'P': rc.PowerKey(); break;    // 收到APFF 動作
                     case 'M': rc.MenuKey();  break;    // 收到AMFF 動作  
                     case 'A': rc.AutoKey();  break;    // 收到AAFF 動作  
                     case 'D': rc.DnKey(); break;      // 收到ADFF 動作  
                     case 'U': rc.UpKey(); break;     // 收到AUFF 動作  
                     default: break;    
                     }  
                 value.index = buffer[i+2];       
                 value.test = 0xff; 
                 value.test_mix = 0xff;
                 clearbuf();          // 清除buffer        
                 break;
                 }else if((buffer[i] == 'T')&&(buffer[i+3] == 'F')){
                    value.test = buffer[i+1];        
                    if(value.test == '4'){
                      value.test_mix = buffer[i+2];
                      Serial.print("test_mix =");
                      Serial.println(value.test_mix);                                            
                    }

                    value.index = buffer[i+2];  
                    Serial.print("test1 start ");  
                    Serial.print(buffer[i+1]);
                    Serial.print(" index ");  
                    Serial.println(value.index);                    
                    clearbuf();         // 清除buffer                             
                    break;
                }        
      }
    }
  }
  testhandler();  
}

void clearbuf(){
  for(int i =0;i<10;i++)
      buffer[i] = 0xfe;
  counter = 0;    
  value.times = 1000;  
  value.steptest = 0;
  value.looptime = 0;
  value.mix_index = 0;
  value.max_looptime = 10;
  value.looptime_mix = 0;
  value.change_state = false;
}

void testhandler(){   // 測試流程控制
  switch(value.test){
    case '0': rc.test0(&value); break;    
    case '1': rc.test1(&value); break;        
    case '2': rc.test2(&value); break;        
    case '3': rc.test3(&value); break;        
    case '4': test4(); break;        
    case '5': rc.test5(&value); break;        
    case '6': rc.test6(&value); break;        
  }
}

void test4(){
   if(value.duration_relay > value.times){  
   int mix_index_max = 3;
   if(value.test_mix == '0'){
        mix_index_max = 7;
        switch(value.mix_index){
            case 0: rc.PowerKey(); value.startTime_relay = millis(); value.times = 20000; value.looptime++; value.max_looptime = 3; break;     
            case 1: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 2: value.index = '1'; rc.test1(&value); value.max_looptime = 20; break;
            case 3: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 4: value.index = '1'; rc.test5(&value); value.max_looptime = 20; break;     
            case 5: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 6: value.index = '3'; rc.test6(&value); value.max_looptime = 20; break;       
            case 7: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;   
            default: break;
        }       
   }else if(value.test_mix == '1'){
        mix_index_max = 7;
        switch(value.mix_index){
            case 0: rc.PowerKey(); value.startTime_relay = millis(); value.times = 20000; value.looptime++; value.max_looptime = 3; break;     
            case 1: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 2: value.index = '1'; rc.test1(&value); value.max_looptime = random(2,10); break;            
            case 3: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 4: value.index = '1'; rc.test5(&value); value.max_looptime = random(2,10); break;     
            case 5: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 6: value.index = '3'; rc.test6(&value); value.max_looptime = random(2,10); break;          
            case 7: value.startTime_relay = millis(); value.times = 20000; value.mix_index++; break;            
            default: break;
        }            
   }else if(value.test_mix == '2'){
        mix_index_max = 13;
        switch(value.mix_index){
            case 0: value.index = '0'; rc.test1(&value); value.max_looptime = random(2,10); break;            
            case 1: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 2: value.index = '1'; rc.test1(&value); value.max_looptime = random(2,10); break;            
            case 3: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 4: value.index = '0'; rc.test2(&value); value.max_looptime = random(2,10); break;     
            case 5: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 6: value.index = '0'; rc.test3(&value); value.max_looptime = random(2,10); break;     
            case 7: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 8: value.index = '1'; rc.test5(&value); value.max_looptime = random(2,10); break;     
            case 9: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;               
            case 10: value.index = '0'; rc.test5(&value); value.max_looptime = random(2,10); break;     
            case 11: value.startTime_relay = millis(); value.times = 20000; value.mix_index++;break;                           
            case 12: value.index = '3'; rc.test6(&value); value.max_looptime = random(2,10); break;          
            case 13: value.startTime_relay = millis(); value.times = 20000; value.mix_index++; break;            
            default: break;
        }            
   }   
   if(value.looptime > value.max_looptime){
      value.mix_index++;
      value.looptime = 0;
      Serial.print("mix_index =");
      Serial.println(value.mix_index);                
   }   
   
   if(value.mix_index > mix_index_max){
       value.mix_index = 0;
       value.looptime_mix++;
       Serial.print("looptime_mix =");
       Serial.println(value.looptime_mix);                    
   }
   }
   value.duration_relay = millis() - value.startTime_relay;                
}
