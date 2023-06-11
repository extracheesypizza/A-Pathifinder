#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>
#include <sstream>

#include "Node.hpp"

using namespace std;

// Bool functions for node accessability
static bool inBounds(int &x, int &y, int &i, int &j, int &n)
{
    // check if the node is inside the grid
    return x + i >= 0 && x + i < n && y + j >= 0 && y + j < n;
}

static bool notCurrent(int &i, int &j)
{
    // check if the node is not the current one
    return !(i == 0 && j == 0);
}

// A* helper functions
static Node *lowestFscore(vector<Node *> &open)
{
    Node *res;
    float min = __FLT_MAX__;
    for(int i = 0; i < open.size(); i++)
        if(open[i]->getFScore() < min)
        {
            min = open[i]->getFScore();
            res = open[i];
        }
    return res;
}

static float getDistance(Node *&cur, Node *&neighbour)
{
    float diffX = cur->getX() - neighbour->getX();
    float diffY = cur->getY() - neighbour->getY();

    return sqrt(diffX * diffX + diffY * diffY);
}

static bool isNumeric(string str)
{
    for(int i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
            return false;
    return true;
}

static int toInt(string str)
{
    stringstream conversion;
    int res;
    conversion << str;
    conversion >> res;
    return res;
}

#endif  // FUNCTIONS_HPP
