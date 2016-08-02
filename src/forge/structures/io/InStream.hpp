#ifndef __HG__FORGE__STRUCTURES__IO__INSTREAM_HPP__
#define __HG__FORGE__STRUCTURES__IO__INSTREAM_HPP__

#include <istream>
#include "../DynamicString.hpp"


namespace forge {
namespace structures {
namespace io {

    struct InStream {

        InStream(std::istream &inStream);
        virtual ~InStream();

      protected:
        std::istream &_InStream;

      public:

        InStream &operator >>(DynamicString &str);
        InStream &operator >>(int &integer);
        InStream &operator >>(unsigned int &unsignedInteger);
        InStream &operator >>(long int &longInteger);
        InStream &operator >>(unsigned long int &unsignedLongInteger);
        InStream &operator >>(char &character);

    };

}   // namespace io
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__IO__INSTREAM_HPP__
