#include "functions.hpp"
#include "boid.hpp"
#include "constants.hpp"

#include <SFML/Graphics.hpp>
#include <cassert>
#include <cmath>
#include <random>

using bd::Boid;
using vector2 = sf::Vector2f;

float bd::randomFloat(float minimum, float maximum)
{
  std::random_device seed;
  std::default_random_engine engine(seed());
  std::uniform_real_distribution<float> unif(minimum, maximum);
  float randomNumber = unif(engine);
  assert(randomNumber >= minimum && randomNumber <= maximum);
  return randomNumber;
}

vector2 bd::randomVelocity(float minimum, float maximum)
{
  float rho   = bd::randomFloat(minimum, maximum);
  float theta = bd::randomFloat(0, 2.f * M_PIf);
  return {rho * std::cos(theta), rho * std::sin(theta)};
}

float bd::rotation(const vector2& velocity)
{
  float angleRadians =
      std::atan2(velocity.y, velocity.x) + M_PI_2f; // M_PI? è il miglior modo?
  float angleDegrees = angleRadians * 360.f / (2.f * M_PIf);
  return angleDegrees;
}

void bd::toroidalSpace(Boid& boid)
{
  vector2 position = boid.getPosition();
  boid.setPositionX(std::fmod(position.x + bd::windowWidth, bd::windowWidth));
  assert(boid.getPosition().x >= 0.f
         && boid.getPosition().x <= bd::windowWidth);
  boid.setPositionY(std::fmod(position.y + bd::windowHeight, bd::windowHeight));
  assert(boid.getPosition().y >= 0.f
         && boid.getPosition().y <= bd::windowHeight);
}