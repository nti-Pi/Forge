#ifndef __HG__FORGE__STRUCTURES__ARRAY_HPP__
#define __HG__FORGE__STRUCTURES__ARRAY_HPP__

#include <cstdarg>
#include "../memory.hpp"

#include "array/resize_strategy.hpp"
#include "exceptions/array.hpp"


namespace forge {
namespace structures {

    using namespace array::resize_strategy;

    /**
     *  DArray (short for Dynamic Array) is a resizable container that stores all variables in a contiguous block of memory.
     *  It is designed to mimic and substitute std::vector from the C++ standard library.
     *  It allows for:
     *      ->  Bounds-checks in debug-mode, and fast performance in release-mode with no external code-modification.
     *      ->  Manipulation of elements, resizing, insertions, and append-operations
     *          ->  Append operations in DArray are different than in std::vector
     *          ->  push_back returns a pointer to the new memory location, which can then be populated with data with the help
     *              of the placement-new operator and an apt constructor.
     *              NO MORE COMPULSORY DEFAULT CONSTRUCTORS!
     *          ->  push_back does not explicitly allocate memory.
     *              This is done to encourage the programmer to pause to think about whether or not it is possible to pre-reserve
     *              the additional memory required. This improves performance, and makes this container more memory-friendly; a
     *              major goal for Forge.
     *          ->  If you wish to explicitly allocate memory, use force_push_back instead.
     *          ->  Similarly, to de-allocate memory on popping, use force_pop_back.
     *      ->  Initializing from a list of literals / objects provided in the constructor
     *      ->  O(1) random access, O(n) traversal
     *      ->  Compatibility with procedures in stdlib's algorithm (eg: std::sort)
     */
    template <typename T,
              typename TLen = unsigned int,
              ResizeStrategyFP<TLen> ResizeStrategy = fitStrat<TLen> >
    struct DArray {  // virtual
        DArray();
        DArray(DArray<T, TLen, ResizeStrategy> &other);
        DArray(TLen len, T buffer[]);
        DArray(TLen len, ...);

        ~DArray();

        /**
         *  The 'reserve' method resizes the buffer, allocating at least enough memory space for (targetBufferSize)
         *  elements according to the ResizeStrategy provided.
         *  It increases or decreases the capacity without changing the length.
         *  In Debug Mode, reserving less memory capacity than the existing length throws a ShrinkUnderflowError.
         */
        void  reserve(TLen targetBufferSize);

        /**
         *  The 'resize' sets the capacity to be at least (targetLen) according to the ResizeStrategy provided, and
         *  sets the length to this value as well.
         *  In Debug Mode, resizing to a length less than the existing length throws a ShrinkUnderflowError.
         */
        void  resize(TLen targetLen);

        /**
         *  Allocates memory for an appended cell of data according to the provided ResizeStrategy and returns a pointer
         *  to it, for use in a placement pointer, after incrementing the length of the array.
         */
        T    *force_push_back();

        /**
         *  Pops the last element in the array and shrinks the size of the memory block according to the ResizeStrategy
         *  provided, along with a decrement in the length.
         */
        void  force_pop_back();

        T    *push_back();
        void  pop_back();

        T &front();     // Returns reference to *this[0]
        T &back();      // Returns reference to *this[this->length - 1]

        T *begin();     // Returns this->Buffer + 0
        T *end();       // Returns this->Buffer + this->length

      protected:
        T    *_Buffer;
        TLen  _BufferLen;

        TLen  _Length;

      public:

        inline T const *buffer() { return _Buffer; }
        inline TLen     length() { return _Length; }

      public:

        T &operator [](TLen index);

    };


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    DArray<T, TLen, ResizeStrategy>::DArray()
        : _Buffer((T *)forge_cmem_malloc(sizeof(T))),
          _BufferLen(1),
          _Length(0) { }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    DArray<T, TLen, ResizeStrategy>::DArray(DArray<T, TLen, ResizeStrategy> &other)
        : _Buffer((T *)forge_cmem_malloc(other._BufferLen * sizeof(T))),
          _BufferLen(other._BufferLen),
          _Length(other._Length) {
        // Copying the elements in:
        memccpy(_Buffer, other._Buffer, 1, _Length * sizeof(T));
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    DArray<T, TLen, ResizeStrategy>::DArray(TLen len, T buffer[])
        : DArray() {
        this->resize(len);
        memcpy(_Buffer, buffer, len * sizeof(T));
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    DArray<T, TLen, ResizeStrategy>::DArray(TLen len, ...)
        : DArray() {
        this->resize(len);

        va_list args;
        va_start(args, len);

        for (TLen i = 0; i < len; ++i)
            _Buffer[i] = va_arg(args, T);

        va_end(args);
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    DArray<T, TLen, ResizeStrategy>::~DArray() {
        if (_Buffer != nullptr)
            free(_Buffer);

        _BufferLen = 0;
        _Length = 0;
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    void DArray<T, TLen, ResizeStrategy>::reserve(TLen bufferLen) {
        TLen newBufferLen = ResizeStrategy(bufferLen);

        if (newBufferLen != _BufferLen) {
            #ifdef __FORGE__DBG__
                if (newBufferLen < _Length)
                    throw exceptions::array::ShrinkOverflowError(_Length, newBufferLen);
            #endif // __FORGE__DBG__

            _BufferLen = newBufferLen;
            _Buffer = (T *)forge_cmem_realloc(_Buffer, sizeof(T) * _BufferLen);
        }
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    void DArray<T, TLen, ResizeStrategy>::resize(TLen len) {
        reserve(len);
        _Length = len;
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    T &DArray<T, TLen, ResizeStrategy>::operator [](TLen index) {
        #ifdef __FORGE__DBG__
            if (index >= _Length) {
                throw exceptions::array::IndexError(index, _Length);
            }
        #endif // __FORGE__DBG__

        return _Buffer[index];
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    T *DArray<T, TLen, ResizeStrategy>::push_back() {
        // push_back simply increases the length count and returns the last position in memory
        // of an array of the new size.
        // It makes no attempt to allocate this memory.
        // This memory is ideally reserved before-hand.
        // If you want to mimic the push_back functionality of std::vector, use force_push_back.

        ++_Length;

        #ifdef __FORGE__DBG__
            if (_Length > _BufferLen) {
                throw exceptions::array::OverflowError();
            }
        #endif // __FORGE__DBG__

        return &back();
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    T *DArray<T, TLen, ResizeStrategy>::force_push_back() {
        // force_push_back resizes the buffer using the ResizeStrategy and returns a pointer to
        // the allocated memory.
        reserve(_Length + 1);
        return push_back();
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    void DArray<T, TLen, ResizeStrategy>::pop_back() {
        // pop_back does not re-allocate the memory block, behaving exactly like std::vector's
        // pop_back method.
        // Ideally, one should make multiple pops and then
        --_Length;
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    void DArray<T, TLen, ResizeStrategy>::force_pop_back() {
        // force_pop_back pops the last element and then resizes the memory to fit using
        // the resize strategy.
        pop_back();
        reserve(_Length);
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    T &DArray<T, TLen, ResizeStrategy>::front() {
        return _Buffer[0];
    }



    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    T &DArray<T, TLen, ResizeStrategy>::back() {
        return _Buffer[_Length - 1];
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    T *DArray<T, TLen, ResizeStrategy>::begin() {
        return _Buffer;
    }


    template <typename T, typename TLen,
              ResizeStrategyFP<TLen> ResizeStrategy>
    T *DArray<T, TLen, ResizeStrategy>::end() {
        return _Buffer + _Length;
    }


}   // namespace structures
}   // namespace forge

#endif // __HG__FORGE__STRUCTURES__ARRAY_HPP__
