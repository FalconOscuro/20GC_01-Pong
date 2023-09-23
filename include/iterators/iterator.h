#ifndef ITERATOR_H
#define ITERATOR_H

#include "nodes/node.h"

class Iterator
{
public:
    virtual Node* Next() = 0;
    virtual bool Finished() const = 0;
};

#endif // ITERATOR_H