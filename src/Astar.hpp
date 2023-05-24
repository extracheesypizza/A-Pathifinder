#ifndef ASTAR_H
#define ASTAR_H

#include "Viewer.hpp"

class AStar
{
   private:
    vector<Node *> *open_;
    vector<Node *> *closed_;
    vector<Node *> *path_;

   public:
    AStar(){};

    void pathfind(Grid *grid, Viewer *view);
};

#endif  // ASTAR_H
