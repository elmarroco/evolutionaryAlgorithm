#include "Agent.h"
#include "Population.h"
#include "my_random.h"
#include "functions.h"
#include <vector>
#include <algorithm>
#include <iostream>

bool compareAgents(Agent a, Agent b)
{
  return a.f < b.f;
}

int main(int argc, char const *argv[])
{
  int gmax = atoi(argv[1]);
  int n_population = atoi(argv[2]);
  int n_agent = atoi(argv[3]);
  double upper_bound = atof(argv[4]);
  double lower_bound = atof(argv[5]);
  int num_function = atoi(argv[5]);
  std::vector<double> v;
  for (size_t i = 0; i < n_agent; i++)
  {
    v.push_back(0);
  }

  Agent a = Agent(0, v);
  std::vector<Agent> agentVector;
  for (size_t i = 0; i < n_population; i++)
  {
    agentVector.push_back(a);
  }
  Population P = Population(agentVector);
  P.initialize(lower_bound, upper_bound);
  P.evaluate(num_function);
  for (size_t t = 0; t < gmax; t++)
  {
    Agent b = P.getBest();
    double r1 = 2 - (2 * t / gmax);
    Population Q = P.createNewPopulation(b, lower_bound, upper_bound, r1);
    Q.evaluate(num_function);
    P = P.updatePopulation(Q);
    std::sort(P.agents.begin(), P.agents.end(), compareAgents);
    P.agents.erase(P.agents.begin() + n_population, P.agents.end());
  }
  std::cout << P.agents[0].f << std::endl;
  return 0;
}
