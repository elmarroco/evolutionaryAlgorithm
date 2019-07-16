#ifndef POPULATION_H
#define POPULATION_H

#include <limits>
#include <assert.h>
#include <cmath>
#include <algorithm>

#include "Agent.h"
#include "functions.h"
#include "my_random.h"

class Population
{
public:
  std::vector<Agent> agents;
  Population(std::vector<Agent> &);
  void initialize(double, double);
  void evaluate(int);
  Agent getBest();
  Population createNewPopulation(Agent &, double, double, double);
  Population createNewPopulationDE(double, double);
  Population updatePopulation(Population &);
  void printPopulation();
};

Population::Population(std::vector<Agent> &_agents)
{
  agents = _agents;
}

void Population::initialize(double lower_bound, double upper_bound)
{
  for (size_t i = 0; i < agents.size(); i++)
  {
    agents[i].initialize(lower_bound, upper_bound);
  }
}

void Population::evaluate(int func)
{
  for (size_t i = 0; i < agents.size(); i++)
  {
    switch (func)
    {
    case 1:
      f1(agents[i]);
      break;
    case 2:
      f2(agents[i]);
      break;
    case 3:
      f3(agents[i]);
      break;
    default:
      f1(agents[i]);
      break;
    }
  }
}

Agent Population::getBest()
{
  int idx = -1;
  double minimum = std::numeric_limits<double>::max();
  for (size_t i = 0; i < agents.size(); i++)
  {
    if (agents[i].f < minimum)
    {
      minimum = agents[i].f;
      idx = i;
    }
  }
  assert(idx > -1);
  return agents[idx];
}

Population Population::createNewPopulation(Agent &a, double lower_bound, double upper_bound, double r1)
{
  std::vector<double> temp_x;
  for (size_t i = 0; i < a.x.size(); i++)
  {
    temp_x.push_back(0);
  }
  std::vector<Agent> temp_vector;
  for (size_t i = 0; i < agents.size(); i++)
  {
    temp_vector.push_back(Agent(0, temp_x));
  }
  Population new_population = Population(temp_vector);
  for (size_t i = 0; i < agents.size(); i++)
  {
    double r4 = generateRandomdouble(0, 1);
    double t1 = generateRandomdouble(0, 1);
    double t2 = generateRandomdouble(0, 1);
    double r2 = 2 * M_PI * t1;
    double r3 = 2 * t2;
    std::vector<double> x;
    double temp;
    for (size_t j = 0; j < agents[i].x.size(); j++)
    {
      if (r4 < 0.5)
        temp = agents[i].x[j] + r1 * sin(r2) * abs(r3 * a.x[j] - agents[i].x[j]);
      else
        temp = agents[i].x[j] + r1 * cos(r2) * abs(r3 * a.x[j] - agents[i].x[j]);
      if (lower_bound <= temp <= upper_bound)
        x.push_back(temp);
      else
        x.push_back(std::max(std::min(agents[i].x[j], upper_bound), lower_bound));
    }
    new_population.agents[i].x = x;
  }
  return new_population;
}

Population Population::createNewPopulationDE(double lower_bound, double upper_bound)
{
  std::vector<double> temp_x;
  for (size_t i = 0; i < agents[0].x.size(); i++)
  {
    temp_x.push_back(0);
  }
  std::vector<Agent> temp_vector;
  for (size_t i = 0; i < agents.size(); i++)
  {
    temp_vector.push_back(Agent(0, temp_x));
  }
  Population new_population = Population(temp_vector);
  double temp;
  for (size_t i = 0; i < agents.size(); i++)
  {
    std::vector<double> x;
    for (size_t j = 0; j < agents[i].x.size(); j++)
    {
      int a = generateRandomInt(0, agents.size() - 1);
      int b = generateRandomInt(0, agents.size() - 1);
      int c = generateRandomInt(0, agents.size() - 1);
      while (a == b || a == c || a == i || b == c || b == i || c == i)
      {
        a = generateRandomInt(0, agents.size() - 1);
        b = generateRandomInt(0, agents.size() - 1);
        c = generateRandomInt(0, agents.size() - 1);
      }
      double CR = 1;
      double F = 0.5;
      double r = generateRandomdouble(0, 1.000001);
      if (r < CR)
        temp = agents[a].x[j] + F * (agents[b].x[j] - agents[c].x[j]);
      else
        temp = agents[i].x[j];
      if (lower_bound <= temp <= upper_bound)
        x.push_back(temp);
      else
        x.push_back(std::max(std::min(agents[i].x[j], upper_bound), lower_bound));
    }
    new_population.agents[i].x = x;
  }
  return new_population;
}

Population Population::updatePopulation(Population &Q)
{
  std::vector<Agent> _agents;
  _agents.reserve(agents.size() + Q.agents.size());
  _agents.insert(_agents.end(), agents.begin(), agents.end());
  _agents.insert(_agents.end(), Q.agents.begin(), Q.agents.end());
  return Population(_agents);
}

void Population::printPopulation()
{
  for (auto agent : agents)
  {
    agent.printAgent();
  }
}

#endif // !POPULATION_H
