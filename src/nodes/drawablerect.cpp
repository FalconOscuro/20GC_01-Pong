#include "nodes/drawablerect.h"

DrawableRect::DrawableRect()
{}

void DrawableRect::Accept(Visitor* visitor)
{
    visitor->Visit(this);
}