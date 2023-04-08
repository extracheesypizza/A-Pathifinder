#ifndef VIEWER_H
#define VIEWER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

#include "Grid.hpp"

using namespace std;

class Viewer
{
   private:
    sf::Font font_;
    sf::RenderWindow *window_;

   public:
    Viewer(){};

    void setState(string s);
    string getState();

    sf::Font getFont();

    void setupWindow(sf::RenderWindow *window);

    void drawStartup(string s);
    void drawGrid(Grid *grid);

    sf::RenderWindow *getWindow();
};

#endif  // VIEWER_H
