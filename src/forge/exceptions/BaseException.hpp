#ifndef __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__
#define __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__

#include <stdexcept>
#include "../structures/StaticString.hpp"


namespace forge {
    using namespace structures;

namespace exceptions {

    struct BaseException {
        BaseException();
        virtual ~BaseException();

        virtual void writeMessage();
        virtual void throwEx() final;

      protected:
        StaticString<64> _MessageBuffer;
    };

}   // namespace exceptions
}   // namespace forge


#endif // __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__
