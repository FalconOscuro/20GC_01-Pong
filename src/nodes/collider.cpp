#include "nodes/collider.h"

Collider::Collider():
    DrawableRect()
{}

void Collider::OnCollide(Collider* collider)
{
    (void)collider;
}

void Collider::Accept(Visitor* visitor)
{
    visitor->Visit(this);
}