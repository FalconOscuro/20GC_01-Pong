#include "nodes/node.h"

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
    // Out of memory error
    if (m_ChildCount >= CHILD_MAX)
        return;
    
    m_Children[m_ChildCount++] = child;

    // Does not account for changing parents
    child->m_Parent = this;
}

Node* Node::GetChild(const uint8_t index) const
{
    // Throw out of range error
    if (index >= CHILD_MAX || index >= m_ChildCount)
        return nullptr;

    return m_Children[index];
}

uint8_t Node::GetChildCount() const
{
    return m_ChildCount;
}

void Node::Accept(Visitor* v) const
{
    v->Visit(this);
}

void Node::Update(float deltaTime)
{
    (void)deltaTime;
}