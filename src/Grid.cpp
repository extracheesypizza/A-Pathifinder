#include "Grid.hpp"

void Grid::setWall(int &x, int &y, bool &b) { grid_[x][y]->setWall(b); }
bool Grid::getWall(int &x, int &y) const { return grid_[x][y]->isWall(); }

int Grid::getSize() const { return grid_.size(); }
Node *Grid::getNode(int x, int y) const { return grid_[x][y]; }

Node *Grid::getStartNode() const { return startNode_; }

void Grid::setStartNode(Node *node)
{
    if(startNode_ != nullptr)
    {
        startNode_->setStartState(false);
        startNode_->setGScore(__FLT_MAX__);
        startNode_->setFScore(__FLT_MAX__);
    }

    startNode_ = node;

    startNode_->setStartState(true);
    startNode_->setGScore(float(0));
    if(goalNode_)
    {
        // cout << getDistance(startNode_, goalNode_) << endl;
        startNode_->setFScore(getDistance(startNode_, goalNode_));
    }
}

Node *Grid::getGoalNode() const { return goalNode_; }
void Grid::setGoalNode(Node *node)
{
    if(goalNode_)
        goalNode_->setGoalState(false);

    goalNode_ = node;
    goalNode_->setGoalState(true);
    if(startNode_)
        startNode_->setFScore(getDistance(startNode_, goalNode_));
}

vector<Node *> *Grid::getOpenSet() { return &openSet_; }
vector<Node *> *Grid::getClosedSet() { return &closedSet_; };
vector<Node *> *Grid::getPathSet() { return &pathSet_; };

void Grid::clearOpenSet() { openSet_.clear(); }
void Grid::clearClosedSet() { closedSet_.clear(); }
void Grid::clearPathSet() { pathSet_.clear(); }

void Grid::clearNodeSets()
{
    clearOpenSet();
    clearClosedSet();
    clearPathSet();
}

void Grid::resetNodes()
{
    for(int i = 0; i < grid_.size(); i++)
        for(int j = 0; j < grid_[i].size(); j++)
        {
            if(grid_[i][j] != startNode_)
            {
                grid_[i][j]->setGScore(__FLT_MAX__);
                grid_[i][j]->setFScore(__FLT_MAX__);
            }
            else
            {
                grid_[i][j]->setGScore(0);
                grid_[i][j]->setFScore(getDistance(grid_[i][j], goalNode_));
            }
        }
}

bool Grid::notWall(int &x, int &y, int &i, int &j) const
{
    // check if the node is not a wall or behind a wall
    if(abs(i) + abs(j) > 1)
        return (this->getNode(x + i, y)->isWall() == 0 || this->getNode(x, y + j)->isWall() == 0) && this->getNode(x + i, y + j)->isWall() == 0;

    else
        return this->getNode(x + i, y + j)->isWall() == 0;
}

vector<Node *> Grid::getNeighbours(Node *&cur) const
{
    vector<Node *> res;
    int x = cur->getX();
    int y = cur->getY();

    int n = this->getSize();

    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if(inBounds(x, y, i, j, n) && notCurrent(i, j) && this->notWall(x, y, i, j))
                res.push_back(this->getNode(x + i, y + j));

    return res;
}
