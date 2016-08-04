#ifndef __HG__FORGE__STRUCTURES__STATICSTRING_HPP__
#define __HG__FORGE__STRUCTURES__STATICSTRING_HPP__

#include <cstring>

#include "BString.hpp"
#include "../array/SArray.hpp"

using namespace forge::structures::array;


namespace forge {
namespace structures {
namespace string {

    template <TStringLen Length>
    struct SString : public BString {
        SString();
        SString(SArray<char, TStringLen, Length> charArray);

      protected:
        SArray<char, TStringLen, Length> _Buffer;

      public:
        virtual inline const char *buffer() override { return _Buffer.buffer(); }
    };


    template <TStringLen Length>
    SString<Length>::SString()
        : _Buffer("\0") { }


    template <TStringLen Length>
    SString<Length>::SString(SArray<char, TStringLen, Length> charArray) {
        strcpy(_Buffer, charArray.buffer());
    }

}   // namespace string
}   // namespace structures
}   // namespace forge


#define str(X) SString<sizeof(X)>(X)


#endif // __HG__FORGE__STRUCTURES__STATICSTRING_HPP__
