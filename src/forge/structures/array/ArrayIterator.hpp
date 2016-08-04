#ifndef __HG__FORGE__STRUCTURES__ARRAY__ARRAYITERATOR_HPP__
#define __HG__FORGE__STRUCTURES__ARRAY__ARRAYITERATOR_HPP__


namespace forge {
namespace structures {

    template <typename T, typename TLen>
    struct ArrayIterator {
        // Compatibility with debug iterator's constructor:
        ArrayIterator(T *pointer)
            : _Pointer(pointer) { }
        virtual ~ArrayIterator() { }

      protected:
        T *_Pointer;

      public:
        inline T *pointer() { return _Pointer; }

      public:
        inline ArrayIterator  operator +=(TLen offset) { _Pointer += offset; return *this; }
        inline ArrayIterator  operator -=(TLen offset) { _Pointer += offset; return *this; }

        inline ArrayIterator  operator ++() { ++_Pointer; return *this; }
        inline ArrayIterator  operator --() { --_Pointer; return *this; }

        inline ArrayIterator  operator  +(TLen offset) { return ArrayIterator(pointer() + offset); }
        inline ArrayIterator  operator  -(TLen offset) { return ArrayIterator(pointer() - offset); }

        inline bool           operator ==(ArrayIterator<T, TLen> other) { return pointer() == other.pointer(); }
        inline bool           operator !=(ArrayIterator<T, TLen> other) { return !(*this == other); }
    };

}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__ARRAY__ARRAYITERATOR_HPP__

