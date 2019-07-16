#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>

#include "Agent.h"

void f1(Agent &a)
{
  a.f = 0;
  for (size_t i = 0; i < a.x.size(); i++)
  {
    a.f += pow(a.x[i] - M_PI, 2);
  }
}

void f2(Agent &a)
{
  a.f = 0;
  for (size_t j = 0; j < a.x.size(); j++)
  {
    for (size_t i = 0; i < j; i++)
    {
      a.f += pow(a.x[i] - M_PI, 2);
    }
  }
}

void f3(Agent &a)
{
  a.f = 0;
  for (size_t i = 0; i < a.x.size() - 1; i++)
  {
    a.f = 100 * pow(a.x[i + 1] - pow(a.x[i], 2), 2) + pow(1 - a.x[i], 2);
  }
}

#endif // FUNCTIONS_H
