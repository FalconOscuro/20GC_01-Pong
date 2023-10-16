#ifndef DRAWABLERECT_H
#define DRAWABLERECT_H

#include "node.h"
#include "maths/rect.h"
#include "visitors/visitor.hpp"

class DrawableRect : public Node
{
public:
    DrawableRect();

    Rect Rectangle;

    void Accept(Visitor* visitor) const override;
};

#endif // DRAWABLERECT_H