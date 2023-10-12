#ifndef RECT_H
#define RECT_H

#include "vector2.h"

/// @brief Axis aligned rectangle
struct Rect
{
    Rect();
    Rect(Vector2 pos, Vector2 size);

    /// @brief Rect Rect collision detection
    bool Intersects(const Rect& rect) const;

    /// @brief Rect Vector2 collision detection
    bool ContainsPoint(const Vector2& v) const;

    Vector2 Position;
    Vector2 Size;
}; // struct Rect


#endif // RECT_H