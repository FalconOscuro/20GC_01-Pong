#ifndef DETECTCOLLISION_H
#define DETECTCOLLISION_H

#include "visitor.hpp"
#include "iterators/dfs.h"

#include <vector>

class DetectCollision : Visitor
{
public:
    DetectCollision(Node* root);
    ~DetectCollision();

    void Visit(Collider* collider) override;

    void Run();

private:
    Iterator_DFS m_Iterator;

    std::vector<Collider*> m_Colliders;
};

#endif // DETECTCOLLISION_H