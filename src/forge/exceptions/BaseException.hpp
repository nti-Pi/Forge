#ifndef __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__
#define __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__

#include <stdexcept>
#include "../structures/string/SString.hpp"


namespace forge {
    using namespace structures;

namespace exceptions {

    struct BaseException {
        BaseException();
        virtual ~BaseException();

        virtual void writeMessage();
        virtual void throwEx() final;

      protected:
        string::SString<64> _MessageBuffer;
    };

}   // namespace exceptions
}   // namespace forge


#endif // __HG__FORGE__EXCEPTIONS__BASEEXCEPTION_HPP__
