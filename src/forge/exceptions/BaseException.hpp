#ifndef __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__
#define __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__

#include <stdexcept>

#include "../logging/Log.hpp"


namespace forge {
namespace exceptions {

    struct BaseException : std::exception {
        virtual const char *what() throw() final {
            generateMessage();
            logging::err::print("EXCEPTION: \"%s\"", _Message);
            return _Message;
        }

        virtual void generateMessage() = 0;

      protected:
        static
        const unsigned int EXCEPTION_MESSAGE_SIZE = 256;

        char _Message[EXCEPTION_MESSAGE_SIZE];
    };

}   // namespace exceptions
}   // namespace forge


#endif // __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__
