#include "flock.hpp"

using bd::Flock;
using boidVector = std::vector<bd::Boid>;

int Flock::getNumberBoids() const
{
  return parameters_.numberBoids;
}

boidVector Flock::getFlock() const
{
  return flock_;
}