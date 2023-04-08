#include "Application.hpp"

#include "Astar.cpp"
#include "Grid.cpp"
#include "Viewer.cpp"

void Application::handleResize(sf::Event event)
{
    sf::Vector2u windowSize;

    float min;
    if(event.size.width < event.size.height)
        min = event.size.width;
    else
        min = event.size.height;

    windowSize.x = min;
    windowSize.y = min;

    window_->setSize(windowSize);

    window_->setView(sf::View(sf::FloatRect(0, 0, min, min)));
}

void Application::handleEventStartup(sf::Event event, string& number)
{
    if(event.type == sf::Event::Closed)
        window_->close();

    if(event.type == sf::Event::Resized)
        handleResize(event);

    if(event.type == sf::Event::TextEntered)
        if(event.text.unicode >= 48 && event.text.unicode <= 57)
            number += event.text.unicode;

    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Enter)
            if(isNumeric(number) && number != "")
                executeGrid(toInt(number));

        if(event.key.code == sf::Keyboard::Backspace && number.size() != 0)
            number.erase(number.size() - 1);
    }
    view_->drawStartup(number);
}

void Application::executeStartup()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Griddy");

    window_ = &window;
    window_->setView(sf::View(sf::FloatRect(0, 0, window_->getSize().x, window_->getSize().y)));
    view_->setupWindow(window_);

    string number;

    while(window_->isOpen())
    {
        sf::Event event;
        while(window_->pollEvent(event))  //
            handleEventStartup(event, number);
    }
}

void Application::switchCurrentMode(sf::Event& event, int& curMode)
{
    switch(event.text.unicode)
    {
        case startUnicode:
            curMode = startUnicode;
            break;

        case wallUnicode:
            curMode = wallUnicode;
            break;

        case endUnicode:
            curMode = endUnicode;
            break;
    }
}

void Application::setNodeStates(int& curMode, Node*& prevNode)
{
    float width = window_->getSize().x / float(grid_->getSize());
    int mouseX = sf::Mouse::getPosition(*window_).x / width;
    int mouseY = sf::Mouse::getPosition(*window_).y / width;

    if(mouseX >= 0 && mouseX < grid_->getSize() && mouseY >= 0 && mouseY < grid_->getSize())
    {
        Node* pressedNode = grid_->getNode(mouseX, mouseY);
        bool prevWallState;

        if(pressedNode == prevNode)
            prevWallState = pressedNode->isWall();

        else
        {
            prevWallState = !pressedNode->isWall();
            prevNode = pressedNode;
        }

        switch(curMode)
        {
            case startUnicode:
                grid_->setStartNode(pressedNode);
                break;

            case wallUnicode:
                pressedNode->setWall(prevWallState);
                break;

            case endUnicode:
                grid_->setGoalNode(pressedNode);
                break;
        }
        view_->drawGrid(grid_);
    }
}

void Application::handleEventGrid(sf::Event event, int& curMode)
{
    if(event.type == sf::Event::Closed)
        window_->close();

    if(event.type == sf::Event::Resized)
        handleResize(event);

    if(event.type == sf::Event::TextEntered)
        switchCurrentMode(event, curMode);

    if(event.type == sf::Event::MouseButtonPressed)
    {
        Node* prevNode = nullptr;
        while(sf::Mouse::isButtonPressed(sf::Mouse::Left))  //
            setNodeStates(curMode, prevNode);
    }

    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Enter)
        {
            if(grid_->getStartNode() && grid_->getGoalNode())
            {
                grid_->clearNodeSets();
                pathfinder_->pathfind(grid_, view_);
                grid_->resetNodes();
            }
        }
    }

    view_->drawGrid(grid_);
}

void Application::executeGrid(int n)
{
    grid_ = new Grid(n);
    pathfinder_ = new AStar();
    int curMode = startUnicode;

    while(window_->isOpen())
    {
        sf::Event event;
        while(window_->pollEvent(event))  //
            handleEventGrid(event, curMode);
    }
}
