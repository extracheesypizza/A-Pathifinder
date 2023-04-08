#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
   private:
    int x_;
    int y_;
    float fScore_ = __FLT_MAX__;
    float gScore_ = __FLT_MAX__;
    bool startState_ = 0;
    bool goalState_ = 0;
    bool wall_ = 0;
    Node* parent_;

   public:
    Node(int x, int y) : x_(x), y_(y){};
    ~Node();

    // Methods
    int getX();
    int getY();

    void setWall(bool b);
    bool isWall();

    void setGScore(float f);
    float getGScore();

    void setFScore(float f);
    float getFScore();

    void setStartState(bool b);
    void setGoalState(bool b);

    Node* getParent();
    void setParent(Node* n);

    bool isStart();
    bool isGoal();
};

#endif  // NODE_H
