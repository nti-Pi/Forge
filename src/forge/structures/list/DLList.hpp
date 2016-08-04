#ifndef __HG__FORGE__STRUCTURES__DLLIST_HPP__
#define __HG__FORGE__STRUCTURES__DLLIST_HPP__

#include "../../memory.hpp"
#include "../exceptions.hpp"
#include "DLNode.hpp"
#include "DLIterator.hpp"

using namespace forge::structures::exceptions;


namespace forge {
namespace structures {
namespace list {

    template <typename TData>
    struct DLList {

        DLList();
        DLList(DLList<TData> &other);
        ~DLList();

        void pop_front();
        void pop_back();
        TData *push_front();
        TData *push_back();

        void                erase(DLIterator<TData> &it);
        DLIterator<TData>   insert(DLIterator<TData> &it);

      protected:
        DLNode<TData> *_Root;
        DLNode<TData> *_Tip;
        TData          _Data;

      public:
        inline DLNode<TData> *root() { return _Root; }
        inline DLNode<TData> *tip()  { return _Tip; }
        inline TData         &data() { return _Data; }

        // Aliases:
        TData &front()  { return _Root->data(); }
        TData &back()   { return _Tip->data();  }

        bool empty()    { return _Root == nullptr; }

        // Iteration:
        inline DLIterator<TData> begin() { return DLIterator<TData>(_Root); }
        inline DLIterator<TData> end()   { return DLIterator<TData>(nullptr); };

    };


    template <typename TData>
    DLList<TData>::DLList()
        : _Root(nullptr),
          _Tip(nullptr) { }


    template <typename TData>
    DLList<TData>::DLList(DLList<TData> &data)
        : DLList() {
        for (auto it = data.begin(); it != data.end(); ++it)
            new(push_back()) TData(it.node()->data());
    }


    template <typename TData>
    DLList<TData>::~DLList() {
        while (!empty())
            pop_back();
    }


    template <typename TData>
    void DLList<TData>::pop_front() {
        #ifdef __FORGE__DBG__
            if (_Root == nullptr)
                throw UnderflowError();
        #endif

        DLNode<TData> *newRoot = _Root->next();
        forge_del _Root;

        if (newRoot != nullptr) {
            newRoot->prev() = nullptr;
            _Root = newRoot;
        }
        else {
            _Tip = _Root = nullptr;
        }
    }


    template <typename TData>
    void DLList<TData>::pop_back() {
        #ifdef __FORGE__DBG__
            if (_Root == nullptr)
                throw UnderflowError();
        #endif // __FORGE__DBG__

        DLNode<TData> *newTip = _Tip->prev();
        forge_del _Tip;

        if (newTip != nullptr) {
            newTip->next() = nullptr;
            _Tip = newTip;
        }
        else {
            _Tip = _Root = nullptr;
        }
    }


    template <typename TData>
    TData *DLList<TData>::push_front() {
        DLNode<TData> *newRoot = (DLNode<TData> *)forge_cmem_malloc(sizeof(DLNode<TData>));
        newRoot->next() = _Root;
        newRoot->prev() = nullptr;

        if (_Root != nullptr)
            _Root->prev() = newRoot;

        _Root = newRoot;

        return &(newRoot->data());
    }


    template <typename TData>
    TData *DLList<TData>::push_back() {
        DLNode<TData> *newTip = (DLNode<TData> *)forge_cmem_malloc(sizeof(DLNode<TData>));
        newTip->next() = nullptr;
        newTip->prev() = _Tip;

        if (_Tip != nullptr)
            _Tip->next() = newTip;
        else
            _Root = newTip;

        _Tip = newTip;

        return &(newTip->data());
    }


    template <typename TData>
    void DLList<TData>::erase(DLIterator<TData> &it) {
        #ifdef __FORGE__DBG__
            if (it.node() == nullptr)
                throw UnderflowError();
        #endif // __FORGE__DBG__

        DLNode<TData> *prev = it.node()->prev();
        DLNode<TData> *next = it.node()->next();

        if (prev != nullptr)
            prev->next() = next;
        if (next != nullptr)
            next->prev() = prev;

        forge_cmem_free(it.node());
        it.node() = prev;
    }


    template <typename TData>
    DLIterator<TData> DLList<TData>::insert(DLIterator<TData> &it) {

    }


}   // namespace list
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__DLLIST_HPP__
