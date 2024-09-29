#include "cell.hpp"
#include "boid.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using bd::Cell;
using vector2      = sf::Vector2f;
using boidPointers = std::vector<bd::Boid*>;
using cellPointers = std::vector<bd::Cell*>;

float Cell::getWidth() const
{
  return width_;
}

float Cell::getHeight() const
{
  return height_;
}

vector2 Cell::getCenter() const
{
  return center_;
}

boidPointers Cell::getBoidsInCell() const
{
  return boidsInCell_;
}

cellPointers Cell::getNearCells() const
{
  return nearCells_;
}

void Cell::setWidth(float width)
{
  width_ = width;
}

void Cell::setHeight(float height)
{
  height_ = height;
}

void Cell::setCenter(vector2 center)
{
  center_ = center;
}