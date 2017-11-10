#include "Color.h"

Color::Color(unsigned int r, unsigned int g, unsigned int b)
{
  rValue = r;
  gValue = g;
  bValue = b;
}

void Color::setRed(unsigned int value)
{
  rValue = value;
}

unsigned int Color::getRed()
{
  return rValue;
}

void Color::setGreen(unsigned int value)
{
  gValue = value;
}

unsigned int Color::getGreen()
{
  return gValue;
}

void Color::setBlue(unsigned int value)
{
  bValue = value;
}

unsigned int Color::getBlue()
{
  return bValue;
}

