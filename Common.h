
#ifndef COMMON_H  //预编译指令，防止重复定义类
#define COMMON_H


typedef struct test_value{
  unsigned long startTime_relay;                 // 起始時間
  unsigned long duration_relay;                  // 持續時間  
  char test;
  char test_mix;
  int times;
  int steptest;
  int looptime;
  int looptime_mix;
  int mix_index;
  int max_looptime;  
  char index;  
  unsigned change_state:1;  
}Test_value ,*pTest_value;

#endif
