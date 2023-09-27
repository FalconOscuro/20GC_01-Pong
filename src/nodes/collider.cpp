#include "nodes/collider.h"

Collider::Collider():
    DrawableRect()
{}

void Collider::Accept(Visitor* visitor) const
{
    visitor->Visit(this);
}