#include "DString.hpp"

#include <cstdio>
#include <cstring>
#include "../../memory.hpp"


namespace forge {
namespace structures {
namespace string {

    DString::DString()
        : _Buffer(nullptr) { }


    DString::DString(const char *buffer) {
        size_t len = strlen(buffer);
        _Buffer = forge_new char[len + 1];

        // Copying:
        for (size_t i = 0; i < len; ++i)
            _Buffer[i] = buffer[i];
    }


    DString::~DString() {
        forge_del _Buffer;
    }


    void DString::resizeBuffer(TStringLen newLen) {
        _Buffer = (char *)forge_cmem_realloc(_Buffer, sizeof(char) * newLen);
    }


    void DString::writef(const char *format, ...) {
        va_list args;
        va_start(args, format);

        TStringLen bufferSize = vsnprintf(NULL, 0, format, args) + 1;
        resizeBuffer(bufferSize + 1);
        vsprintf(_Buffer, format, args);

        va_end(args);
    }

}   // namespace string
}   // namespace structures
}   // namespace forge
