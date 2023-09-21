#ifndef RECT_H
#define RECT_H

#include "node.h"


class Rect : public Node
{
public:
    Rect();

    Vector2 Size;

    bool ContainsPoint(const Vector2& p) const;
};

#endif // RECT_H