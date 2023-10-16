#ifndef NODE_H
#define NODE_H

#include "maths/vector2.h"
#include "visitors/visitor.hpp"

#include <cstdint>

#define CHILD_MAX 8

/// @brief Game object super class
/// @details Base class used to describe an object in 2D space
class Node
{
public:
    Node();
    virtual ~Node();

    /// @brief Adds a new child node
    /// @todo Does not return failure if CHILD_MAX is exceeded
    void AddChild(Node* child);

    /// @brief Child getter
    /// @param index child index pos
    /// @return Either pointer to stored child or nullptr if non-existant or index out of range
    Node* GetChild(const uint8_t index) const;
    // DeleteChild
    // FindChild

    /// @return Number of actively stored child nodes
    uint8_t GetChildCount() const;

    /// @brief Calls relevant visitor function for this node type
    /// @note requires re-implementation per node with visitor specific behaviour
    /// @todo Investigate other approaches
    virtual void Accept(Visitor* v) const;

    /// @brief Main update logic
    /// @param deltaTime time taken to process last frame in seconds
    virtual void Update(float deltaTime);

    Vector2 Position;

private:

    Node* m_Children[CHILD_MAX];
    uint8_t m_ChildCount;

    /// @brief Current parent node
    /// @todo Currently no way to handle/prevent nodes with multiple parents
    Node* m_Parent;
};// class Node

#endif // NODE_H