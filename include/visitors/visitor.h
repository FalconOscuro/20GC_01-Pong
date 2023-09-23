#ifndef VISITOR_H
#define VISITOR_H

class Node;
class DrawableRect;

class Visitor
{
public:
    virtual void Visit(const Node*) = 0;

    virtual void Visit(const DrawableRect*) = 0;
};

#endif // VISITOR_H