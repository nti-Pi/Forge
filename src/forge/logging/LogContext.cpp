#include "LogContext.hpp"

#include "../memory.hpp"


namespace forge {
namespace logging {

    using namespace structures::io;


    LogContext::LogContext(structures::DynamicString userName,
                           OutStream outputStream,
                           bool mentionUser)
        : _PassThroughStream(outputStream) {
        if (mentionUser) {
            // We must construct a prefix!
            _PrintPrefix = forge_new structures::DynamicString();
            _PrintPrefix->writef("[%s]: ", userName.buffer());
        }
        else {
            _PrintPrefix = nullptr;
        }
    }

    LogContext::~LogContext() {
        if (_PrintPrefix != nullptr)
            forge_del _PrintPrefix;
    }

    // Operators:
    OutStream &LogContext::operator <<(String *str) {
        return (prefix() == nullptr ? (_PassThroughStream << str) : (_PassThroughStream << prefix() << str));
    }

    OutStream &LogContext::operator <<(structures::DynamicString &str) {
        return (prefix() == nullptr ? (_PassThroughStream << str) : (_PassThroughStream << prefix() << str));
    }

    OutStream &LogContext::operator <<(int data) {
        return (prefix() == nullptr ? (_PassThroughStream << data) : (_PassThroughStream << prefix() << data));
    }

    OutStream &LogContext::operator <<(unsigned int data) {
        return (prefix() == nullptr ? (_PassThroughStream << data) : (_PassThroughStream << prefix() << data));
    }

    OutStream &LogContext::operator <<(long int data) {
        return (prefix() == nullptr ? (_PassThroughStream << data) : (_PassThroughStream << prefix() << data));
    }

    OutStream &LogContext::operator <<(unsigned long int data) {
        return (prefix() == nullptr ? (_PassThroughStream << data) : (_PassThroughStream << prefix() << data));
    }

    OutStream &LogContext::operator <<(float data) {
        return (prefix() == nullptr ? (_PassThroughStream << data) : (_PassThroughStream << prefix() << data));
    }

    OutStream &LogContext::operator <<(double data) {
        return (prefix() == nullptr ? (_PassThroughStream << data) : (_PassThroughStream << prefix() << data));
    }

    OutStream &LogContext::operator <<(char data) {
        return (prefix() == nullptr ? (_PassThroughStream << data) : (_PassThroughStream << prefix() << data));
    }

    DynamicString *LogContext::prefix() { return _PrintPrefix; }


}   // namespace logging
}   // namespace forge
