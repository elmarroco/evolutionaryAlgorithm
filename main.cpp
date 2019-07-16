#include <iostream>
#include "algorithms.h"

int main(int argc, char const *argv[])
{
  int algorithm_choice = atoi(argv[1]);
  int gmax = atoi(argv[2]);
  int population_size = atoi(argv[3]);
  int agent_size = atoi(argv[4]);
  double lower_bound = atof(argv[5]);
  double upper_bound = atof(argv[6]);
  int function_choice = atoi(argv[7]);
  int experiment = atoi(argv[8]);

  double res;
  switch (algorithm_choice)
  {
  case 1:
    res = sca(gmax, population_size, agent_size, lower_bound, upper_bound, function_choice);
    break;
  case 2:
    res = de(gmax, population_size, agent_size, lower_bound, upper_bound, function_choice);
    break;
  default:
    break;
  }
  std::cout << algorithm_choice << " " << function_choice << " " << experiment << " " << res << std::endl;
  return 0;
}