#include "Node.hpp"

int Node::getX() const { return x_; }
int Node::getY() const { return y_; }

void Node::setWall(bool b) { wall_ = b; }
bool Node::isWall() const { return wall_; }

void Node::setGScore(float f) { gScore_ = f; }
float Node::getGScore() const { return gScore_; }

void Node::setFScore(float f) { fScore_ = f; }
float Node::getFScore() const { return fScore_; }

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

bool Node::isStart() const { return startState_; }
bool Node::isGoal() const { return goalState_; }

Node *Node::getParent() const { return parent_; };
void Node::setParent(Node *node) { parent_ = node; };
