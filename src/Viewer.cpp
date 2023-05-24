#include "Viewer.hpp"

void Viewer::setupWindow(sf::RenderWindow *window)
{
    window_ = window;
    if(!font_.loadFromFile("arial.ttf"))
    {
        // std::cout << "ERROR LOADING FONT" << std::endl;
        return;
    }
    drawStartup("");
    // window_->setFramerateLimit(60);
}

sf::Font Viewer::getFont()
{
    // return working font
    return font_;
}

void Viewer::drawStartup(string s)
{
    window_->clear(sf::Color::White);

    sf::Text title;
    title.setFont(font_);
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::Red);
    title.setStyle(sf::Text::Bold);
    title.setString("A* Pathfinding Algorithm");
    title.setPosition(window_->getSize().x / 2 - title.getGlobalBounds().width / 2, 100);

    window_->draw(title);

    sf::Text input;
    input.setFont(font_);
    input.setCharacterSize(24);
    input.setFillColor(sf::Color::Red);
    input.setStyle(sf::Text::Bold);
    input.setString("Input the size of the grid:");
    input.setPosition(window_->getSize().x / 2 - input.getGlobalBounds().width / 2, window_->getSize().y / 2 - 50);

    window_->draw(input);

    sf::Text textNumber;
    textNumber.setFont(font_);
    textNumber.setCharacterSize(24);
    textNumber.setFillColor(sf::Color::Red);
    textNumber.setStyle(sf::Text::Bold);
    textNumber.setString(s);
    textNumber.setPosition(window_->getSize().x / 2 - textNumber.getGlobalBounds().width / 2, window_->getSize().y / 2);

    window_->draw(textNumber);

    window_->display();
}

void Viewer::drawGrid(Grid *grid)
{
    window_->clear(sf::Color::White);

    int n = grid->getSize();
    float width = window_->getSize().x / float(n);

    sf::Vector2f vec;
    vec.x = width;
    vec.y = width;

    vector<Node *> *open = grid->getOpenSet();
    vector<Node *> *closed = grid->getClosedSet();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sf::RectangleShape node(vec);
            node.setPosition(sf::Vector2f(width * i, width * j));
            node.setOutlineColor(sf::Color::Black);
            node.setOutlineThickness(2);

            Node *curNode = grid->getNode(i, j);

            if(find(open->begin(), open->end(), curNode) != open->end())
                node.setFillColor(sf::Color::Green);

            if(find(closed->begin(), closed->end(), curNode) != closed->end())
                node.setFillColor(sf::Color::Red);

            if(curNode->isWall() == 1)
                node.setFillColor(sf::Color::Black);

            if(curNode->isStart())
                node.setFillColor(sf::Color::Blue);

            if(curNode->isGoal())
                node.setFillColor(sf::Color::Cyan);

            window_->draw(node);
        }
    }

    vec.x -= 2;
    vec.y -= 2;
    vector<Node *> path = *grid->getPathSet();
    if(!path.empty())
    {
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i]->isWall() != 1)
            {
                sf::RectangleShape node(vec);
                node.setPosition(sf::Vector2f(width * path[i]->getX(), width * path[i]->getY()));
                node.setFillColor(sf::Color::Yellow);
                window_->draw(node);
            }
        }
    }

    window_->display();
}
