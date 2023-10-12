#ifndef ITERATOR_H
#define ITERATOR_H

#include "nodes/node.h"

/// @brief Virtual node iterator
class Iterator
{
public:

    /// @return Pointer to next Node or nullptr if finished
    virtual Node* Next() = 0;

    /// @return true if end of iteration queue reached
    virtual bool Finished() const = 0;
}; // class Iterator

#endif // ITERATOR_H