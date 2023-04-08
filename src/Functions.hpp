#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

#include "Node.cpp"

using namespace std;

// Bool functions for node accessability
bool inBounds(int &x, int &y, int &i, int &j, int &n)
{
    // check if the node is inside the grid
    return x + i >= 0 && x + i < n && y + j >= 0 && y + j < n;
}

bool notCurrent(int &i, int &j)
{
    // check if the node is not the current one
    return !(i == 0 && j == 0);
}

// A* helper functions
Node *lowestFscore(vector<Node *> &open)
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

float getDistance(Node *&cur, Node *&neighbour)
{
    float diffX = cur->getX() - neighbour->getX();
    float diffY = cur->getY() - neighbour->getY();

    return diffX * diffX + diffY * diffY;
}

bool isNumeric(string str)
{
    for(int i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
            return false;
    return true;
}

int toInt(string str)
{
    stringstream conversion;
    int res;
    conversion << str;
    conversion >> res;
    return res;
}

#endif  // FUNCTIONS_H
