#ifndef __HG__FORGE__STRUCTURES__EXCEPTIONS__COMMON_HPP__
#define __HG__FORGE__STRUCTURES__EXCEPTIONS__COMMON_HPP__

#include "../exceptions/BaseException.hpp"


namespace forge {
namespace structures {
namespace exceptions {

    struct IndexError : public forge::exceptions::BaseException {

        IndexError(size_t index, size_t arrayLength);
        virtual ~IndexError();
        virtual void writeMessage() override;

      protected:
        size_t _Index;
        size_t _Length;

    };


    struct OverflowError : public forge::exceptions::BaseException {
        OverflowError();
        virtual ~OverflowError();

        virtual void writeMessage() override;
    };


    struct UnderflowError : public forge::exceptions::BaseException {
        UnderflowError();
        virtual ~UnderflowError();

        virtual void writeMessage() override;
    };

}   // namespace exceptions
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__EXCEPTIONS__COMMON_HPP__
