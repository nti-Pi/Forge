#ifndef __HG__FORGE__LOGGING__LOGMANAGER_HPP__
#define __HG__FORGE__LOGGING__LOGMANAGER_HPP__

#include "../structures/String.hpp"
#include "../structures/DynamicString.hpp"
#include "../structures/io/OutStream.hpp"


namespace forge {
namespace logging {

    using namespace structures;
    using namespace structures::io;


    struct LogContext {
        LogContext(structures::DynamicString name,
                   OutStream outputStream,
                   bool mentionUser = false);
        ~LogContext();

      protected:
        OutStream                   _PassThroughStream;
        structures::DynamicString  *_PrintPrefix;

        DynamicString *prefix();

      public:
        inline OutStream &get_PassThroughStream() { return _PassThroughStream; }

      public:
        // Operators:
        OutStream &operator <<(String *str);
        OutStream &operator <<(int integer);
        OutStream &operator <<(unsigned int unsignedInteger);
        OutStream &operator <<(long int longInteger);
        OutStream &operator <<(unsigned long int unsignedLongInteger);
        OutStream &operator <<(float realNumber);
        OutStream &operator <<(double realNumber);
        OutStream &operator <<(char character);

        template <unsigned int length>
        OutStream &operator <<(structures::StaticString<length> str) { return (*this) << &str; }
        OutStream &operator <<(structures::DynamicString &str);
    };

}   // namespace logging
}   // namespace forge


#endif // __HG__FORGE__LOGGING__LOGMANAGER_HPP__
