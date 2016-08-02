#ifndef __HG__FORGE__LOGGING__LOGMANAGER_HPP__
#define __HG__FORGE__LOGGING__LOGMANAGER_HPP__

#include "../structures/BaseString.hpp"
#include "../structures/DString.hpp"
#include "../structures/io/OutStream.hpp"


namespace forge {
namespace logging {

    using namespace structures;
    using namespace structures::io;


    struct LogContext {
        LogContext(DString name,
                   OutStream outputStream,
                   bool mentionUser = false);
        ~LogContext();

      protected:
        OutStream    _PassThroughStream;
        DString     *_PrintPrefix;

        DString     *prefix();

      public:
        inline OutStream &get_PassThroughStream() { return _PassThroughStream; }

      public:
        // Operators:
        OutStream &operator <<(BaseString *str);
        OutStream &operator <<(int integer);
        OutStream &operator <<(unsigned int unsignedInteger);
        OutStream &operator <<(long int longInteger);
        OutStream &operator <<(unsigned long int unsignedLongInteger);
        OutStream &operator <<(float realNumber);
        OutStream &operator <<(double realNumber);
        OutStream &operator <<(char character);

        template <unsigned int length>
        OutStream &operator <<(SString<length> str) { return (*this) << &str; }
        OutStream &operator <<(DString &str);
    };

}   // namespace logging
}   // namespace forge


#endif // __HG__FORGE__LOGGING__LOGMANAGER_HPP__
