#include "boid.hpp"
#include "constants.hpp"
#include "flock.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cassert>
#include <vector>

using bd::Boid;
using bd::Flock;
using boidVector = std::vector<Boid>;

int main()
{
  /* std::vector<Boid> flock(30, sf::Color::Green);
  std::generate(flock.begin(), flock.end(),
                []() { return Boid(sf::Color::Green); }); */
                Flock flock(sf::Color::Green);
  sf::RenderWindow window(sf::VideoMode(bd::windowWidth, bd::windowHeight),
                          "Window");
  window.setPosition(sf::Vector2i{10, 10});
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);

    boidVector flockToDraw = flock.getFlock();
    std::for_each(flockToDraw.begin(), flockToDraw.end(),
                  [&](Boid b) { window.draw(b.getShape()); });
    window.display();
    flock.evolve();
  }
}