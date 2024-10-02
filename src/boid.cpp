#include "boid.hpp"
#include "constants.hpp"
#include "functions.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>

using bd::Boid;
using bd::Cell;
using vector2 = sf::Vector2f;

void Boid::setupShape(sf::Color color)
{
  shape_.setPointCount(4);
  shape_.setPoint(0, vector2(0.f, 5.f));
  shape_.setPoint(1, vector2(2.f, 0.f));
  shape_.setPoint(2, vector2(4.f, 5.f));
  shape_.setPoint(3, vector2(2.f, 4.f));
  shape_.setFillColor(color);
  shape_.setOrigin({2.f, 2.5f});
  shape_.setScale(bd::shapeScale, bd::shapeScale);
}

Boid::Boid()
{} // necessario?

Boid::Boid(sf::Color color)
    : position_{bd::randomFloat(0.f, bd::windowWidth),
                bd::randomFloat(0.f, bd::windowHeight)}
    , velocity_{bd::randomVelocity(bd::minimumSpeed, bd::maximumSpeed)}
    , cellPointer_{nullptr}
{
  assert(position_.x >= 0.f
         && position_.x
                <= bd::windowWidth); // non so se posso mettere gli assert qua
  assert(position_.y >= 0.f && position_.y <= bd::windowHeight);
  assert(velocity_.x >= bd::minimumSpeed && velocity_.x <= bd::maximumSpeed);
  assert(velocity_.y >= bd::minimumSpeed && velocity_.y <= bd::maximumSpeed);
  Boid::setupShape(color);
  shape_.setPosition(position_);
  shape_.setRotation(bd::rotation(velocity_));
}

Boid::Boid(const vector2& position, const vector2& velocity,
           const sf::Color& color)
    : position_{position}
    , velocity_{velocity}
{
  Boid::setupShape(color);
  shape_.setPosition(position);
  shape_.setRotation(bd::rotation(velocity));
}

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