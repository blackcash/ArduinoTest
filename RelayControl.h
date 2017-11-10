#ifndef RELAYCONTROL_H  //预编译指令，防止重复定义类
#define RELAYCONTROL_H
#include "Common.h"

class RelayControl
{
private:    

public:
    RelayControl(); //类的构造函数，与类名相同
    void initKey();
    void MenuKey();
    void PowerKey();
    void AutoKey();
    void UpKey();
    void DnKey();
    void test0(pTest_value value);
    void test1(pTest_value value);    
    void test2(pTest_value value);    
    void test3(pTest_value value);    
    void test5(pTest_value value);    
    void test6(pTest_value value);        
};

#endif // RELAYCONTROL_H

