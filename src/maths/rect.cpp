#include "maths/rect.h"

Rect::Rect()
{}

Rect::Rect(Vector2 pos, Vector2 size):
    Position(pos), Size(size)
{}

bool Rect::Intersects(const Rect& rect) const
{
    return Position.X < rect.Position.X + rect.Size.X &&
        Position.Y < rect.Position.Y + rect.Size.Y &&
        Position.X + Size.X > rect.Position.X &&
        Position.Y + Size.Y > rect.Position.Y;
}

bool Rect::ContainsPoint(const Vector2& v) const
{
    return v.X < Position.X + Size.X &&
        v.X > Position.X &&
        v.Y < Position.Y + Size.Y &&
        v.Y > Position.Y;
}