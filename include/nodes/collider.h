#ifndef COLLIDER_H
#define COLLIDER_H

#include "drawablerect.h"

class Collider : public DrawableRect
{
public:
    Collider();

    void Accept(Visitor* visitor) const override;
};

#endif // COLLIDER_H