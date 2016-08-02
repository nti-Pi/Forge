#ifndef __HG__FORGE__STRUCTURES__STRING_HPP__
#define __HG__FORGE__STRUCTURES__STRING_HPP__

#include "BaseString.hpp"
#include <cstdarg>


namespace forge {
namespace structures {

    typedef unsigned int TStringLen;

    struct BaseString {

        virtual const char *buffer() = 0;
        virtual void writef(const char *format, ...);

    };

}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__STRING_HPP__
