#ifndef GRID_H
#define GRID_H

#include "Functions.hpp"

using namespace std;

class Grid
{
   private:
    vector<vector<Node *>> grid_;
    vector<Node *> openSet_;
    vector<Node *> closedSet_;
    vector<Node *> pathSet_;

    Node *startNode_ = nullptr;
    Node *goalNode_ = nullptr;

   public:
    Grid(int &n)
    {
        vector<Node *> row;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)  //
                row.push_back(new Node(i, j));
            grid_.push_back(row);
            row.clear();
        }
    };

    ~Grid();

    void setWall(int &x, int &y, bool &b);
    bool getWall(int &x, int &y);
    int getSize();
    Node *getNode(int x, int y);

    Node *getStartNode();
    void setStartNode(Node *node);

    Node *getGoalNode();
    void setGoalNode(Node *node);

    bool notWall(int &x, int &y, int &i, int &j);

    vector<Node *> *getOpenSet();
    vector<Node *> *getClosedSet();
    vector<Node *> *getPathSet();

    void clearOpenSet();
    void clearClosedSet();
    void clearPathSet();

    void clearNodeSets();

    void resetNodes();

    void statistics();

    vector<Node *> getNeighbours(Node *&cur);
};

#endif  // GRID_H
