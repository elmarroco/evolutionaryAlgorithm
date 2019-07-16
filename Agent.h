#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <iostream>

#include "my_random.h"

class Agent
{
public:
  double f;
  std::vector<double> x;
  Agent();
  Agent(double, std::vector<double> &);
  void initialize(double lower_bound, double upper_bound);
  void printAgent();
};

Agent::Agent()
{
  f = 0;
}

Agent::Agent(double _f, std::vector<double> &_x)
{
  f = _f;
  x = _x;
}

void Agent::initialize(double lower_bound, double upper_bound)
{
  for (size_t i = 0; i < x.size(); i++)
  {
    x[i] = generateRandomdouble(lower_bound, upper_bound);
  }
}

void Agent::printAgent()
{
  std::cout << "f = " << f << std::endl;
  for (auto sol : x)
  {
    std::cout << sol << " ";
  }
  std::cout << std::endl;
}

#endif //AGENT_H