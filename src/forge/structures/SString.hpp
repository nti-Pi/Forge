#ifndef __HG__FORGE__STRUCTURES__STATICSTRING_HPP__
#define __HG__FORGE__STRUCTURES__STATICSTRING_HPP__

#include "BaseString.hpp"
#include <cstring>

#define str(X) SString<sizeof(X)>(X)

#include "SArray.hpp"


namespace forge {
namespace structures {

    template <TStringLen Length>
    struct SString : public BaseString {
        SString();
        SString(SArray<char, Length> charArray);

      protected:
        SArray<char, Length> _Buffer;

      public:
        virtual inline const char *buffer() override { return _Buffer.buffer(); }
    };


    template <TStringLen Length>
    SString<Length>::SString() {
        _Buffer[0] = '\0';
    }


    template <TStringLen Length>
    SString<Length>::SString(SArray<char, Length> charArray) {
        strcpy(_Buffer, charArray.buffer());
    }

}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__STATICSTRING_HPP__
