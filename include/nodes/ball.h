#ifndef BALL_H
#define BALL_H

#include "collider.h"

class Ball : public Collider
{
public:
    Ball(Vector2 bounds);

    void Update(float deltaTime) override;

private:
    Vector2 m_Bounds;

    Vector2 m_Velocity;
};

#endif // BALL_H