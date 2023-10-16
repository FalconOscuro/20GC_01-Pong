#ifndef PADDLE_H
#define PADDLE_H

#include "collider.h"

class Paddle : public Collider
{
public:
    Paddle();

    void Update(float deltaTime) override;
};

#endif // PADDLE_H