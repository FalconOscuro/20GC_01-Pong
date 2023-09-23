#include "iterators/dfs.h"

Iterator_DFS::Iterator_DFS(Node* root)
{
    m_NodeStack = std::stack<Node*>();
    m_NodeStack.push(root);
}

Iterator_DFS::~Iterator_DFS()
{}

Node* Iterator_DFS::Next()
{
    if (Finished())
        return nullptr;

    Node* next = m_NodeStack.top();
    m_NodeStack.pop();

    // Place child nodes onto stack
    uint8_t count = next->GetChildCount();
    for (uint8_t i = 0; i < count; i++)
        m_NodeStack.push(next->GetChild(i));

    return next;
}

bool Iterator_DFS::Finished() const
{
    return m_NodeStack.size() == 0;
}