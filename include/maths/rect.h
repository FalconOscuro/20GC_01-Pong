#ifndef RECT_H
#define RECT_H

#include "vector2.h"

struct Rect
{
    Rect();
    Rect(Vector2 pos, Vector2 size);

    bool Intersects(const Rect& rect) const;

    bool ContainsPoint(const Vector2& v) const;

    Vector2 Position;
    Vector2 Size;
};


#endif // RECT_H