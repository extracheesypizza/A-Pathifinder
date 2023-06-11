#ifndef NODE_HPP
#define NODE_HPP

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
    int getX() const;
    int getY() const;

    void setWall(bool b);
    bool isWall() const;

    void setGScore(float f);
    float getGScore() const;

    void setFScore(float f);
    float getFScore() const;

    void setStartState(bool b);
    void setGoalState(bool b);

    Node* getParent() const;
    void setParent(Node* n);

    bool isStart() const;
    bool isGoal() const;
};

#endif  // NODE_HPP
