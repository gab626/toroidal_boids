#ifndef BOID_HPP
#define BOID_HPP

#include <SFML/Graphics.hpp>

using vector2 = sf::Vector2f;

namespace bd {

class Cell;

class Boid
{
 private:
  vector2 position_;
  vector2 velocity_;
  sf::ConvexShape shape_;
  Cell* cellPointer_;
  void setupShape(sf::Color);

 public:
  Boid(); // potrebbe essere omesso (vedi liam)
  Boid(sf::Color);
  Boid(const vector2&, const vector2&, const sf::Color&);
  //   ~Boid();
  vector2
  getPosition() const; // si può facilmente accedere alle singole componenti
  vector2 getVelocity() const;
  sf::ConvexShape getShape() const;
  Cell* getCellPointer() const;
  void setPosition(const vector2&);
  void setVelocity(const vector2&);
  void setPositionX(float);
  void setPositionY(float);
  void setCellPointer(Cell*); // const? &?
};

} // namespace bd

#endif