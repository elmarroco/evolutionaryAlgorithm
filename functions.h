#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>

#include "Agent.h"

void f1(Agent &a)
{
  double f = 0;
  for (size_t i = 0; i < a.x.size(); i++)
  {
    f += pow(a.x[i] - M_PI, 2);
  }
  a.f = f;
}

void f2(Agent &a)
{
}

void f3(Agent &a)
{
}

#endif // FUNCTIONS_H
