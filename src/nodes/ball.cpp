#include "nodes/ball.h"

Ball::Ball(Vector2 bounds):
    Collider()
{
    m_Bounds = bounds;
    m_Velocity = Vector2(100, 100);

    Rectangle.Size = Vector2(10, 10);

    Rectangle.Position = Vector2(50, 50);
}

void Ball::Update(float deltaTime)
{
    if (Rectangle.Position.X < 0 || 
        Rectangle.Position.X + Rectangle.Size.X > m_Bounds.X)
        m_Velocity.X = -m_Velocity.X;
    
    if (Rectangle.Position.Y < 0 ||
        Rectangle.Position.Y + Rectangle.Size.Y > m_Bounds.Y)
        m_Velocity.Y = -m_Velocity.Y;
    
    Rectangle.Position += m_Velocity * deltaTime;
}