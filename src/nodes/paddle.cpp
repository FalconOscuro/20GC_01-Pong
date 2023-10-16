#include "nodes/paddle.h"

#include "core/input/input.hpp"

Paddle::Paddle():
    Collider()
{}

void Paddle::Update(float deltaTime)
{
    if (Input::Get()->IsKeyPressed(Key::W))
        Rectangle.Position.Y -= 100 * deltaTime;
    
    if (Input::Get()->IsKeyPressed(Key::S))
        Rectangle.Position.Y += 100 * deltaTime;
}