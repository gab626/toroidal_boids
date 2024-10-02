#include "flock.hpp"
#include "constants.hpp"
#include "functions.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>

using bd::Boid;
using bd::Flock;
using vector2    = sf::Vector2f;
using boidVector = std::vector<Boid>;

void Flock::updateFlock(boidVector& newBoids)
{
  std::move(newBoids.begin(), newBoids.end(), flock_.begin());
  // manca speedLimit
  std::for_each(flock_.begin(), flock_.end(),
                [](Boid& boid) { toroidalSpace(boid); });
}

Flock::Flock(sf::Color color)
{ // unica costruzione che mi genera bene tutti gli NBoids, da rivedere
  flock_.resize(parameters_.numberBoids);
  std::generate(flock_.begin(), flock_.end(), [&]() { return Boid(color); });
}

long unsigned int Flock::getNumberBoids() const
{
  return parameters_.numberBoids;
}

boidVector Flock::getFlock()
{
  return flock_;
}

void Flock::evolve()
{
  boidVector newBoids(parameters_.numberBoids);
  std::transform(flock_.begin(), flock_.end(), newBoids.begin(),
                 [](Boid& boid) {
                   vector2 newPosition =
                       boid.getPosition() + bd::deltaT * boid.getVelocity();
                   return Boid(newPosition, boid.getVelocity(),
                               boid.getShape().getFillColor());
                 });
                 updateFlock(newBoids);
}