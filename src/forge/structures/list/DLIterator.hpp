#ifndef __HG__FORGE__STRUCTURES__LIST__DLITERATOR_HPP__
#define __HG__FORGE__STRUCTURES__LIST__DLITERATOR_HPP__

#include "DLNode.hpp"


namespace forge {
namespace structures {
namespace list {

    template <typename TData>
    struct DLIterator {
        DLIterator(DLNode<TData> *node)
            : _Node(node) { }

      protected:
        DLNode<TData>  *_Node;

      public:
        DLNode<TData> *&node() { return _Node; }

      public:

        inline DLIterator<TData> &operator ++() {
            if (node() != nullptr)
                node() = node()->next();
            return *this;
        }

        inline DLIterator<TData> &operator --() {
            if (node() != nullptr)
                node() = node()->prev();
            return *this;
        }

        bool               operator ==(DLIterator<TData> other) { return other.node() == node(); }
        bool               operator !=(DLIterator<TData> other) { return !(*this == other); }
    };

}   // namespace list
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__LIST__DLITERATOR_HPP__
