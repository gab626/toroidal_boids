#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "cell.hpp"
#include "flock.hpp"
#include <SFML/Graphics.hpp>

namespace bd {

class Simulation
{
 private:
  sf::RenderWindow mainWindow_;
  bd::Flock greenFlock_;
  std::vector<Cell> grid_;

 public:
  //   Simulation();
  //   ~Simulation();
  // aggiungere costruttore con colori?
  void operator()();
};

} // namespace bd

#endif