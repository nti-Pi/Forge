#ifndef __FORGE__STRUCTURES__EXCEPTIONS__ARRAY_HPP__
#define __FORGE__STRUCTURES__EXCEPTIONS__ARRAY_HPP__

#include "../../exceptions/BaseException.hpp"


namespace forge {
namespace structures {
namespace exceptions {
namespace array {

    struct IndexError : public forge::exceptions::BaseException {

        IndexError(size_t index, size_t arrayLength);
        virtual ~IndexError();
        virtual void writeMessage() override;

      protected:
        size_t _Index;
        size_t _Length;

    };


    struct ShrinkOverflowError : public forge::exceptions::BaseException {
        ShrinkOverflowError(size_t oldLen, size_t newLen);
        virtual ~ShrinkOverflowError();

        virtual void writeMessage() override;

      protected:
        size_t _OldLen;
        size_t _NewLen;
    };



    struct OverflowError : public forge::exceptions::BaseException {
        OverflowError();
        virtual ~OverflowError();

        virtual void writeMessage() override;
    };

}   // namespace array
}   // namespace exceptions
}   // namespace structures
}   // namespace forge


#endif // __FORGE__STRUCTURES__EXCEPTIONS__ARRAY_HPP__
