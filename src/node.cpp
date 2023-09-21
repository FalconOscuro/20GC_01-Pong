#include "node.h"

Node::Node()
{
    Position = Vector2();

    m_ChildCount = 0;
}

Node::~Node()
{}

void Node::AddChild(Node* child)
{
    // Cannot exceed max child count
    // Throw error here?
    if (m_ChildCount >= CHILD_MAX)
        return;
    
    m_Children[m_ChildCount++] = child;

    // Does not account for changing parents
    child->m_Parent = this;
}