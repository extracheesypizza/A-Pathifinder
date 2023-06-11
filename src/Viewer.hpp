#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <SFML/Graphics.hpp>

#include "Grid.hpp"

class Viewer
{
   private:
    sf::Font font_;
    sf::RenderWindow *window_;

   public:
    Viewer(){};

    sf::Font getFont() const;

    void setupWindow(sf::RenderWindow *window);

    void drawStartup(string s) const;
    void drawGrid(Grid *grid) const;
};

#endif  // VIEWER_HPP
