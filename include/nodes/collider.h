#ifndef COLLIDER_H
#define COLLIDER_H

#include "drawablerect.h"

class Collider : public DrawableRect
{
public:
    Collider();

    virtual void OnCollide(Collider* other);

    void Accept(Visitor* visitor) override;
};

#endif // COLLIDER_H