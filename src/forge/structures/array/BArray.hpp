#ifndef __HG__FORGE__STRUCTURES__ARRAY__BARRAY_HPP__
#define __HG__FORGE__STRUCTURES__ARRAY__BARRAY_HPP__

#include "ArrayIterator.hpp"


namespace forge {
namespace structures {

    template <typename T, typename TLen>
    struct BArray {

        virtual T     *buffer() = 0;
        virtual TLen   length() = 0;

        virtual T     &operator [](TLen index) { return buffer()[index]; }

        T &front() { return (*this)[0]; }               // Returns reference to *this[0]
        T &back()  { return (*this)[length() - 1]; }    // Returns reference to *this[this->length - 1]

        ArrayIterator<T, TLen> begin()  { return ArrayIterator<T, TLen>(buffer()); }
        ArrayIterator<T, TLen> end()    { return ArrayIterator<T, TLen>(buffer() + length()); }
    };

}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__ARRAY__BARRAY_HPP__
