#include "builders/pongbuilder.h"

#include "nodes/drawablerect.h"
#include "nodes/ball.h"
#include "nodes/paddle.h"

Node* GetDivider(Vector2 scale)
{
    float size = scale.Y * .02;
    float gap = (scale.Y - (size * 8)) / 8;

    Node* root = new Node();

    float x  = (scale.X / 2) - size / 2;

    for (float y = 0; y < scale.Y; y += size + gap)
    {
        DrawableRect* dot = new DrawableRect();
        dot->Rectangle = Rect(Vector2(x, y), Vector2(size, gap));

        root->AddChild(dot);
    }

    return root;
}

Node* GetGame(Vector2 scale)
{
    Node* root = new Node();

    root->AddChild(GetDivider(scale));
    root->AddChild(new Ball(scale));
    root->AddChild(GetPaddle(scale));


    return root;
}

Node* GetPaddle(Vector2 scale)
{
    Paddle* paddle = new Paddle();
    paddle->Rectangle.Size = Vector2(10, 50);
    paddle->Rectangle.Position = Vector2(50, scale.Y / 2 - 25);

    return paddle;
}