#ifndef CELL_HPP
#define CELL_HPP

#include "boid.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using vector2      = sf::Vector2f;
using boidPointers = std::vector<bd::Boid*>;
using cellPointers = std::vector<bd::Cell*>;

namespace bd {

class Cell
{
 private:
  float width_  = 100.f; // fissati per ora
  float height_ = 100.f;
  vector2 center_;
  boidPointers boidsInCell_;
  cellPointers nearCells_;

 public:
  //   Cell();
  //   ~Cell();
  float getWidth() const;
  float getHeight() const;
  vector2 getCenter() const;
  boidPointers getBoidsInCell() const;
  cellPointers getNearCells() const;
  void setWidth(float);
  void setHeight(float);
  void setCenter(vector2);
  void insertBoid(Boid&);          // const&? forse meglio Boid*
  void setNearCells(cellPointers); // const&?
};

// non sto implementando la classe Grid perché non serve

} // namespace bd

#endif