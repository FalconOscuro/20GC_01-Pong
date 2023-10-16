#include "visitors/detectcollision.h"

#include "nodes/collider.h"

DetectCollision::DetectCollision(Node* root):
    m_Iterator(root)
{}

DetectCollision::~DetectCollision()
{}

void DetectCollision::Visit(Collider* collider)
{
    m_Colliders.push_back(collider);
}

void DetectCollision::Run()
{
    while (!m_Iterator.Finished())
        m_Iterator.Next()->Accept(this);
    
    for (std::size_t i = 0; i < m_Colliders.size() - 1; i++)
    {
        Collider* a = m_Colliders[i];
        for (std::size_t j = i+1; j < m_Colliders.size(); j++)
        {
            Collider* b = m_Colliders[j];

            if (a->Rectangle.Intersects(b->Rectangle))
            {
                a->OnCollide(b);
                b->OnCollide(a);
            }
        }
    }
}