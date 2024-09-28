#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "boid.hpp"
#include <SFML/Graphics.hpp>

using vector2      = sf::Vector2f;
using boidPointers = std::vector<bd::Boid*>;

namespace bd {

float norm(const vector2&); // meglio lavorare con il quadrato delle distanze

float distance(const Boid&, const Boid&); // ritrovare distanza toroidale

// non sto aggiungendo la statistica per ora

float rotation(const vector2&);

void toroidalSpace(vector2&);

// prossimamente aggiungerò le funzioni con Cell e grid

vector2 separationVelocity(float, const boidPointers&, const Boid&);

vector2 alignmentVelocity(float, const boidPointers&, const Boid&);

vector2 cohesionVelocity(float, const boidPointers&, const Boid&);

void speedLimit(Boid&, float); // forse posso togliere float

float randomFloat(float, float);

vector2 randomVelocity(float, float);

} // namespace bd

#endif