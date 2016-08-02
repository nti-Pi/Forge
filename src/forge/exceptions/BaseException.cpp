#include "BaseException.hpp"

#include <iostream>
#include <stdexcept>

#include "../structures/SString.hpp"
#include "../logging.hpp"


namespace forge {
namespace exceptions {

    BaseException::BaseException() { }


    BaseException::~BaseException() { }


    void BaseException::writeMessage() {
        _MessageBuffer.writef("Something went wrong.\n");
    }


    void BaseException::throwEx() {
        writeMessage();
        throw std::runtime_error(_MessageBuffer.buffer());
    }

}   // namespace exceptions
}   // namespace forge
