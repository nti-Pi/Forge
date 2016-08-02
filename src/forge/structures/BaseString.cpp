#include "BaseString.hpp"

#include <cstdio>


namespace forge {
namespace structures {

    void BaseString::writef(const char *format, ...) {
        va_list args_list;
        va_start(args_list, format);

        vsprintf((char *)buffer(), format, args_list);

        va_end(args_list);
    }

}   // namespace structures
}   // namespace forge
