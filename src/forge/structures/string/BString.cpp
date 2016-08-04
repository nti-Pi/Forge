#include "BString.hpp"

#include <cstdio>


namespace forge {
namespace structures {
namespace string {

    void BString::writef(const char *format, ...) {
        va_list args_list;
        va_start(args_list, format);

        vsprintf((char *)buffer(), format, args_list);

        va_end(args_list);
    }

}   // namespace string
}   // namespace structures
}   // namespace forge
