#ifndef FLOCK_HPP
#define FLOCK_HPP

#include "boid.hpp"
#include "cell.hpp"
#include <vector>

using boidVector = std::vector<bd::Boid>;

namespace bd {

// non sto implementando Statistics perché è inutile

struct Parameters
{
  float interactionDistance     = 100.f; // parametri temporaneamente fissati
  float separationDistance      = 30.f;
  float separationCoefficient   = 3.f;
  float alignmentCoefficient    = 0.05f;
  float cohesionCoefficient     = 0.3f;
  long unsigned int numberBoids = 20;
};

class Flock
{
 private:
  Parameters parameters_;
  // Statistics statistics_;
  boidVector flock_;
  //   std::vector<Cell> grid_;
  // void saveStatistics(float, float, float, float);
  // void printStatistics();
  void updateFlock(boidVector&);

 public:
  //   Flock();
  Flock(sf::Color);
  //   ~Flock();
  long unsigned int getNumberBoids() const;
  boidVector getFlock(); // non mi piace
  void evolve();
};

} // namespace bd

#endif