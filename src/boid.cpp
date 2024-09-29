#include "boid.hpp"
#include <SFML/Graphics.hpp>

using bd::Boid;
using bd::Cell;
using vector2 = sf::Vector2f;

vector2 Boid::getPosition() const
{
  return position_;
}

vector2 Boid::getVelocity() const
{
  return velocity_;
}

sf::ConvexShape Boid::getShape() const
{
  return shape_;
}

Cell* Boid::getCellPointer() const
{
  return cellPointer_;
}

void Boid::setPosition(const vector2& position)
{
  position_ = position;
}

void Boid::setVelocity(const vector2& velocity)
{
  velocity_ = velocity;
}

void Boid::setPositionX(float x)
{
  position_.x = x;
}

void Boid::setPositionY(float y)
{
  position_.y = y;
}

void Boid::setCellPointer(Cell* cellPointer)
{
  cellPointer_ = cellPointer;
}