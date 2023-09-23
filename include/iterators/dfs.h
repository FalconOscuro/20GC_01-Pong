#ifndef DFS_H
#define DFS_H

#include "iterator.h"

#include <stack>

class Iterator_DFS : public Iterator
{
public:

    Iterator_DFS(Node* root);
    ~Iterator_DFS();

    Node* Next() override;
    bool Finished() const override;

private:

    std::stack<Node*> m_NodeStack;
};

#endif // DFS_H