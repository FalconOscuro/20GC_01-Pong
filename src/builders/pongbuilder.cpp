#include "builders/pongbuilder.h"

#include "nodes/drawablerect.h"
#include "nodes/ball.h"

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

    return root;
}