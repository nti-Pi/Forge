#ifndef __HG__FORGE__STRUCTURES__STRING_HPP__
#define __HG__FORGE__STRUCTURES__STRING_HPP__

#include "BString.hpp"
#include <cstdarg>


namespace forge {
namespace structures {
namespace string {

    typedef unsigned int TStringLen;

    struct BString {

        virtual const char *buffer() = 0;
        virtual void writef(const char *format, ...);

    };

}   // namespace string
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__STRING_HPP__
