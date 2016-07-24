#ifndef __HG__FORGE__STRUCTURES__LINKEDLIST_H__
#define __HG__FORGE__STRUCTURES__LINKEDLIST_H__

#include "../memory/Allocator.hpp"


// Static:
namespace forge {
namespace structures {

    template <typename T>
    struct LinkedListNode {

        LinkedListNode(LinkedListNode<T> *prev, T value);
        ~LinkedListNode();

        inline
        T &get_Value() { return m_Value; }

        inline
        void set_Prev(LinkedListNode<T> *prev) { m_Prev = prev; }

        inline
        void set_Value(T value) { m_Value = value; }

      protected:
        LinkedListNode<T> *m_Prev;
        T                  m_Value;
    };


    template <typename T>
    LinkedListNode<T>::LinkedListNode()
        : m_Prev(nullptr) { }


    template <typename T>
    LinkedListNode<T>::~LinkedListNode() { }

}   // namespace structures
}   // namespace forge



namespace forge {
namespace structures {

    template <typename T>
    struct LinkedList {

        LinkedList();
        ~LinkedList();

        void push_back(T value);
        void pop_back();

        inline
        T &get_Tip() { return m_Tip->get_Value(); }

      protected:
        LinkedListNode<T> *m_Root;
        LinkedListNode<T> *m_Tip;
    };


    template <typename T>
    LinkedList<T>::LinkedList()
        : m_Root(nullptr),
          m_Tip(nullptr) { }


    template <typename T>
    LinkedList<T>::~LinkedList() {

    }


    template <typename T>
    void LinkedList<T>::push_back(T value) {

    }

}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__LINKEDLIST_H__
