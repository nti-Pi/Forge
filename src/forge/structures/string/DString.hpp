#ifndef __HG__FORGE__STRUCTURES__DYNAMICSTRING_HPP__
#define __HG__FORGE__STRUCTURES__DYNAMICSTRING_HPP__

#include "BString.hpp"


namespace forge {
namespace structures {
namespace string {

    struct DString : public BString {

        DString();
        DString(const char *literal);
        virtual ~DString();

        virtual void writef(const char *format, ...) override;

      protected:
        char        *_Buffer;
        TStringLen   _Length;

        void resizeBuffer(TStringLen newLen);

      public:

        inline
        virtual const char *buffer() override { return (const char *)_Buffer; }

        inline
        virtual char *dbuffer() { return _Buffer; }

    };

}   // namespace string
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__DYNAMICSTRING_HPP__
