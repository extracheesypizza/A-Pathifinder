#include "Astar.hpp"

void AStar::pathfind(Grid *grid, Viewer *view)
{
    Node *start = grid->getStartNode();
    Node *goal = grid->getGoalNode();

    open_ = grid->getOpenSet();
    closed_ = grid->getClosedSet();
    path_ = grid->getPathSet();

    open_->push_back(start);

    while(!open_->empty())
    {
        Node *cur = lowestFscore(*open_);

        if(cur == goal)
        {
            while(goal->getParent() && goal->getParent() != start)
            {
                path_->push_back(goal->getParent());
                goal = goal->getParent();
            }
            return;
        }

        closed_->push_back(cur);
        open_->erase(find(open_->begin(), open_->end(), cur));

        vector<Node *> curNeighbours = grid->getNeighbours(cur);

        for(int i = 0; i < curNeighbours.size(); i++)
        {
            Node *curNeighbour = curNeighbours[i];
            float tempG = cur->getGScore() + getDistance(cur, curNeighbour);

            if(tempG < curNeighbour->getGScore())
            {
                curNeighbour->setParent(cur);
                curNeighbour->setGScore(tempG);
                curNeighbour->setFScore(tempG + getDistance(curNeighbour, goal));

                if(find(open_->begin(), open_->end(), curNeighbour) == open_->end())  //
                    open_->push_back(curNeighbour);
            }
        }
        view->drawGrid(grid);
    }
    return;
}
