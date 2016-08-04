#ifndef __HG__FORGE__STRUCTURES__LIST__DLNODE_HPP__
#define __HG__FORGE__STRUCTURES__LIST__DLNODE_HPP__


namespace forge {
namespace structures {
namespace list {

    template <typename TData>
    struct DLNode {

        DLNode(DLNode<TData> *next,
               DLNode<TData> *prev,
               TData data)
            : _Next(next),
              _Prev(prev),
              _Data(data) { }

        DLNode(DLNode<TData> *next, DLNode<TData> *prev)
            : _Next(next),
              _Prev(prev) { }

        inline DLNode *&next() { return _Next; }
        inline DLNode *&prev() { return _Prev; }
        inline TData   &data() { return _Data; }

      protected:
        DLNode *_Next;
        DLNode *_Prev;
        TData   _Data;

    };

}   // namespace list
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__LIST__DLNODE_HPP__
