#ifndef __HG__FORGE__STRUCTURES__SARRAY_HPP__
#define __HG__FORGE__STRUCTURES__SARRAY_HPP__

#include <cstdarg>


namespace forge {
namespace structures {

    template <typename T, unsigned int Length>
    struct SArray {
        SArray(const T *buffer);
        SArray(...);
        virtual ~SArray();

      protected:
        T _Buffer[Length];

      public:
        inline T &operator [](unsigned int index) { return _Buffer[index]; }

      public:
        inline const T         *buffer() { return _Buffer; }
        constexpr unsigned int  length()  { return Length; }
    };


    template <typename T, unsigned int Length>
    SArray<T, Length>::SArray(const T *buffer) {
        memcpy(_Buffer, buffer, sizeof(T) * Length);
    }


    template <typename T, unsigned int Length>
    SArray<T, Length>::SArray(...) {
        va_list args;
        va_start(args, Length);

        for (unsigned int i = 0; i < Length; ++i)
            _Buffer[i] = va_arg(args, T);

        va_end(args);
    }


    template <typename T, unsigned int Length>
    SArray<T, Length>::~SArray() { }


}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__SARRAY_HPP__
