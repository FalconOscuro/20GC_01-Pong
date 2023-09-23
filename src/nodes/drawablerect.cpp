#include "nodes/drawablerect.h"

DrawableRect::DrawableRect()
{}

void DrawableRect::Accept(Visitor* visitor) const
{
    visitor->Visit(this);
}