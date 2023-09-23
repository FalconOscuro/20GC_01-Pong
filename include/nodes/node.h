#ifndef NODE_H
#define NODE_H

#include "maths/vector2.h"
#include "visitors/visitor.h"

#include <cstdint>

#define CHILD_MAX 8

class Node
{
public:
    Node();
    virtual ~Node();

    void AddChild(Node* child);
    Node* GetChild(const uint8_t index) const;
    // DeleteChild
    // FindChild

    uint8_t GetChildCount() const;

    virtual void Accept(Visitor* v) const;

    Vector2 Position;

private:

    Node* m_Children[CHILD_MAX];
    uint8_t m_ChildCount;

    Node* m_Parent;
};

#endif // NODE_H