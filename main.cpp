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

double sca(int gmax, int population_size, int agent_size, double lower_bound, double upper_bound, int function_choice)
{
  // Creating temp vector
  std::vector<double> v;
  // Initializing temp vector with 0's
  for (size_t i = 0; i < agent_size; i++)
  {
    v.push_back(0);
  }
  // Creating a temp Agent with 0 and the temp vector
  Agent a = Agent(0, v);
  std::vector<Agent> agentVector;
  for (size_t i = 0; i < population_size; i++)
  {
    agentVector.push_back(a);
  }
  Population P = Population(agentVector);
  P.initialize(lower_bound, upper_bound);
  P.evaluate(function_choice);
  for (size_t t = 1; t <= gmax; t++)
  {
    Agent b = P.getBest();
    double r1 = 2 - (2 * t / gmax);
    Population Q = P.createNewPopulation(b, lower_bound, upper_bound, r1);
    Q.evaluate(function_choice);
    P = P.updatePopulation(Q);
    std::sort(P.agents.begin(), P.agents.end(), compareAgents);
    P.agents.erase(P.agents.begin() + population_size, P.agents.end());
  }
  return P.agents[0].f;
}

double de(int gmax, int population_size, int agent_size, double lower_bound, double upper_bound, int function_choice)
{
  // Creating temp vector
  std::vector<double> v;
  // Initializing temp vector with 0's
  for (size_t i = 0; i < agent_size; i++)
  {
    v.push_back(0);
  }
  // Creating a temp Agent with 0 and the temp vector
  Agent a = Agent(0, v);
  std::vector<Agent> agentVector;
  for (size_t i = 0; i < population_size; i++)
  {
    agentVector.push_back(a);
  }
  Population P = Population(agentVector);
  P.initialize(lower_bound, upper_bound);
  P.evaluate(function_choice);
  for (size_t t = 1; t <= gmax; t++)
  {
    Population Q = P.createNewPopulationDE(lower_bound, upper_bound);
    Q.evaluate(function_choice);
    P = P.updatePopulation(Q);
    std::sort(P.agents.begin(), P.agents.end(), compareAgents);
    P.agents.erase(P.agents.begin() + population_size, P.agents.end());
  }
  return P.agents[0].f;
}

int main(int argc, char const *argv[])
{
  int algorithm_choice = atoi(argv[1]);
  int gmax = atoi(argv[2]);
  int population_size = atoi(argv[3]);
  int agent_size = atoi(argv[4]);
  double lower_bound = atof(argv[5]);
  double upper_bound = atof(argv[6]);
  int function_choice = atoi(argv[7]);

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
  std::cout << res << std::endl;
  return 0;
}