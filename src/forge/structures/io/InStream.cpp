#include "InStream.hpp"


namespace forge {
namespace structures {
namespace io {

    InStream::InStream(std::istream &inStream)
        : _InStream(inStream) { }


    InStream::~InStream() {

    }

    InStream &InStream::operator >>(DynamicString &str) {
        this->_InStream >> str.dbuffer();
        return *this;
    }

    InStream &InStream::operator >>(int &integer) {
        this->_InStream >> integer;
        return *this;
    }

    InStream &InStream::operator >>(unsigned int &unsignedInteger) {
        this->_InStream >> unsignedInteger;
        return *this;
    }

    InStream &InStream::operator >>(long int &longInteger) {
        this->_InStream >> longInteger;
        return *this;
    }

    InStream &InStream::operator >>(char &character) {
        this->_InStream >> character;
        return *this;
    }

    InStream &InStream::operator >>(unsigned long int &unsignedLongInteger) {
        this->_InStream >> unsignedLongInteger;
        return *this;
    }

}   // namespace io
}   // namespace structures
}   // namespace forge
