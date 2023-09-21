#include "nodes/rect.h"

Rect::Rect()
{}

bool Rect::ContainsPoint(const Vector2& p) const
{
    return p.X >= Position.X && p.X <= Position.X + Size.X
        && p.Y >= Position.Y && p.Y <= Position.Y + Size.Y;
}