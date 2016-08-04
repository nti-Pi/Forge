#ifndef __FORGE__STRUCTURES__ARRAY__EXCEPTIONS_HPP__
#define __FORGE__STRUCTURES__ARRAY__EXCEPTIONS_HPP__

#include "../../exceptions/BaseException.hpp"


namespace forge {
namespace structures {
namespace array {
namespace exceptions {

    struct ShrinkOverflowError : public forge::exceptions::BaseException {
        ShrinkOverflowError(size_t oldLen, size_t newLen);
        virtual ~ShrinkOverflowError();

        virtual void writeMessage() override;

      protected:
        size_t _OldLen;
        size_t _NewLen;
    };

}   // namespace exceptions
}   // namespace array
}   // namespace structures
}   // namespace forge


#endif // __FORGE__STRUCTURES__ARRAY__EXCEPTIONS_HPP__
