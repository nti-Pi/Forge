#ifndef __HG__FORGE__STRUCTURES__ARRAY__SARRAY_HPP__
#define __HG__FORGE__STRUCTURES__ARRAY__SARRAY_HPP__

#include <cstdarg>
#include "BArray.hpp"


namespace forge {
namespace structures {
namespace array {

    template <typename T, typename TLen, TLen Length>
    struct SArray : public BArray<T, TLen> {
        SArray(const T *buffer);
        SArray(...);
        virtual ~SArray();

      protected:
        T _Buffer[Length];

      public:
        virtual     T    *buffer() { return _Buffer; }
        virtual     TLen  length() { return Length; }       // TODO: ConstExpr this!
    };


    template <typename T, typename TLen, TLen Length>
    SArray<T, TLen, Length>::SArray(const T *buffer) {
        memcpy(_Buffer, buffer, sizeof(T) * Length);
    }


    template <typename T, typename TLen, TLen Length>
    SArray<T, TLen, Length>::SArray(...) {
        va_list args;
        va_start(args, Length);

        for (TLen i = 0; i < Length; ++i)
            if (sizeof(T) < sizeof(int))
                _Buffer[i] = (T)va_arg(args, int);
            else
                _Buffer[i] = va_arg(args, T);

        va_end(args);
    }


    template <typename T, typename TLen, TLen Length>
    SArray<T, TLen, Length>::~SArray() { }


}   // namespace array
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__ARRAY__SARRAY_HPP__
