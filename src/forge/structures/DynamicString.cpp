#include "DynamicString.hpp"

#include <cstdio>
#include <cstring>
#include "../memory.hpp"


namespace forge {
namespace structures {

    DynamicString::DynamicString()
        : _Buffer(nullptr) { }


    DynamicString::DynamicString(const char *buffer) {
        size_t len = strlen(buffer);
        _Buffer = forge_new char[len + 1];

        // Copying:
        for (size_t i = 0; i < len; ++i)
            _Buffer[i] = buffer[i];
    }


    DynamicString::~DynamicString() {
        forge_del _Buffer;
    }


    void DynamicString::resizeBuffer(TStringLen newLen) {
        _Buffer = (char *)forge_cmem_realloc(_Buffer, sizeof(char) * newLen);
    }


    void DynamicString::writef(const char *format, ...) {
        va_list args;
        va_start(args, format);

        TStringLen bufferSize = vsnprintf(NULL, 0, format, args) + 1;
        resizeBuffer(bufferSize + 1);
        vsprintf(_Buffer, format, args);

        va_end(args);
    }

}   // namespace structures
}   // namespace forge
