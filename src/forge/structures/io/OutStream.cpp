#include "OutStream.hpp"


namespace forge {
namespace structures {
namespace io {

    OutStream::OutStream(std::ostream &outStream)
        : _OutStream(outStream) { }


    OutStream::~OutStream() { }


    OutStream &OutStream::operator <<(BaseString *str) {
        this->_OutStream << str->buffer();
        return *this;
    }


    OutStream &OutStream::operator <<(int data) {
        this->_OutStream << data;
        return *this;
    }


    OutStream &OutStream::operator <<(unsigned int data) {
        this->_OutStream << data;
        return *this;
    }


    OutStream &OutStream::operator <<(long int data) {
        this->_OutStream << data;
        return *this;
    }


    OutStream &OutStream::operator <<(unsigned long int data) {
        this->_OutStream << data;
        return *this;
    }


    OutStream &OutStream::operator <<(float data) {
        this->_OutStream << data;
        return *this;
    }


    OutStream &OutStream::operator <<(double data) {
        this->_OutStream << data;
        return *this;
    }

    OutStream &OutStream::operator <<(char data) {
        this->_OutStream << data;
        return *this;
    }


}   // namespace io
}   // namespace structures
}   // namespace forge
