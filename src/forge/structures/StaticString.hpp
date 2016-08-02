#ifndef __HG__FORGE__STRUCTURES__STATICSTRING_HPP__
#define __HG__FORGE__STRUCTURES__STATICSTRING_HPP__

#include "String.hpp"
#include <cstring>

#define str(X) StaticString<sizeof(X)>(X)


namespace forge {
namespace structures {

    template <TStringLen length>
    struct StaticString : public String {
        StaticString();
        StaticString(char literal[length]);

      protected:
        char _Buffer[length];

      public:
        virtual inline const char *buffer() override { return _Buffer; }

    };


    template <TStringLen length>
    StaticString<length>::StaticString() {
        _Buffer[0] = '\0';
    }


    template <TStringLen length>
    StaticString<length>::StaticString(char literal[length]) {
        strcpy(_Buffer, literal);
    }

}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__STATICSTRING_HPP__
