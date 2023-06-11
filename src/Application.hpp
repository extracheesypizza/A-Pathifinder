#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Astar.hpp"

#define startUnicode 122
#define wallUnicode 120
#define endUnicode 99

class Application
{
   private:
    Grid* grid_;
    Viewer* view_;
    AStar* pathfinder_;
    sf::RenderWindow* window_;

   public:
    Application() { view_ = new Viewer(); };

    void executeStartup();
    void executeGrid(int n);
    void executeShow();

    void handleResize();
    void handleEventStartup(sf::Event event, string& number);
    void handleEventGrid(sf::Event event, int& curMode);

    void switchCurrentMode(sf::Event& event, int& curMode);
    void setNodeStates(int& curMode, Node*& prevNode);
};

#endif  // APPLICATION_HPP
