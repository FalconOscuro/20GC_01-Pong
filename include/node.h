#ifndef NODE_H
#define NODE_H

#include "vector2.h"

#include <cstdint>

#define CHILD_MAX 8

class Node
{
public:
    Node();
    virtual ~Node();

    void AddChild(Node* child);

    // GetChild
    // DeleteChild
    // FindChild

    Vector2 Position;

private:

    Node* m_Children[CHILD_MAX];
    uint8_t m_ChildCount;

    Node* m_Parent;
};

#endif // NODE_H