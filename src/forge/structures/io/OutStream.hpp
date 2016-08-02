#ifndef __HG__FORGE__STRUCTURES__IO__OUTSTREAM_HPP__
#define __HG__FORGE__STRUCTURES__IO__OUTSTREAM_HPP__

#include <ostream>

#include "../String.hpp"
#include "../StaticString.hpp"
#include "../DynamicString.hpp"


namespace forge {
namespace structures {
namespace io {

    struct OutStream {

        OutStream(std::ostream &outStream);
        virtual ~OutStream();

      protected:
        std::ostream &_OutStream;

      public:

        OutStream &operator <<(String *str);
        template <unsigned int length>
        OutStream &operator <<(StaticString<length> str) { return (*this) << &str; }
        OutStream &operator <<(DynamicString &str) { return (*this) << &str; }
        OutStream &operator <<(int integer);
        OutStream &operator <<(unsigned int unsignedInteger);
        OutStream &operator <<(long int longInteger);
        OutStream &operator <<(unsigned long int unsignedLongInteger);
        OutStream &operator <<(float realNumber);
        OutStream &operator <<(double realNumber);
        OutStream &operator <<(char character);

    };

}   // namespace io
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__IO__OUTSTREAM_HPP__
