/*
  颜色类，可以分别设置色彩的RGB分量

*/
#ifndef COLOR_H  //预编译指令，防止重复定义类
#define COLOR_H

class Color
{
private:    //私有成员，用来保存色彩的RGB分量
  unsigned int rValue;
  unsigned int gValue;
  unsigned int bValue;

public:
  Color(unsigned int r=255, unsigned int g=0, unsigned int b=0); //类的构造函数，与类名相同
  void setRed(unsigned int value); //类的方法，设置或者读取色彩的RGB分量值
  unsigned int getRed();
  void setGreen(unsigned int value);
  unsigned int getGreen();
  void setBlue(unsigned int value);
  unsigned int getBlue();

};

#endif // COLOR_H

