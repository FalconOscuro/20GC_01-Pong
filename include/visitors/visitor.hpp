#ifndef VISITOR_HPP
#define VISITOR_HPP

class Node;
class DrawableRect;
class Collider;

/// @brief abstract Node Visitor
/// @todo Investigate other approaches
class Visitor
{
public:
    Visitor() {}
    virtual ~Visitor() = 0;

    virtual void Visit(const Node* node) {
        (void)node;
    }

    virtual void Visit(const DrawableRect* drawable) {
        (void)drawable;
    }

    virtual void Visit(const Collider* collider) {
        (void)collider;
    }
    // Visit functions defined here to prevent repetetive code on visitor implementations
    // parameter is voided to prevent compiler warnings
}; // class Visitor

#endif // VISITOR_HPP