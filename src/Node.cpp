#include "Node.hpp"

int Node::getX() { return x_; }
int Node::getY() { return y_; }

void Node::setWall(bool b) { wall_ = b; }
bool Node::isWall() { return wall_; }

void Node::setGScore(float f) { gScore_ = f; }
float Node::getGScore() { return gScore_; }

void Node::setFScore(float f) { fScore_ = f; }
float Node::getFScore() { return fScore_; }

void Node::setStartState(bool b)
{
    startState_ = b;
    wall_ = 0;
}
void Node::setGoalState(bool b)
{
    goalState_ = b;
    wall_ = 0;
}

bool Node::isStart() { return startState_; }
bool Node::isGoal() { return goalState_; }

Node *Node::getParent() { return parent_; };
void Node::setParent(Node *node) { parent_ = node; };
