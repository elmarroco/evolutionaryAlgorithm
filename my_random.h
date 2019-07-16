#ifndef MYRANDOM_H
#define MYRANDOM_H

#include <random>

double generateRandomdouble(double lower_bound, double upper_bound)
{
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution<double> dis(lower_bound, upper_bound);
  return dis(gen);
}

double generateRandomInt(int lower_bound, int upper_bound)
{
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<int> dis(lower_bound, upper_bound);
  return dis(gen);
}
#endif //MYRANDOM_H
