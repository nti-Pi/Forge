#include "String.hpp"

#include <cstdio>


namespace forge {
namespace structures {

    void String::writef(const char *format, ...) {
        va_list args_list;
        va_start(args_list, format);

        vsprintf((char *)buffer(), format, args_list);

        va_end(args_list);
    }

}   // namespace structures
}   // namespace forge
