#include "logging.hpp"

#include "memory.hpp"
#include "logging/LogContext.hpp"



namespace forge {
namespace logging {

    using namespace structures;
    using namespace structures::io;

    LogContext *_GlobalStdOutContext = nullptr;
    LogContext *_GlobalErrOutContext = nullptr;


    void init(OutStream out, OutStream err) {
        _GlobalStdOutContext = forge_new LogContext("Global", out, true);
        _GlobalErrOutContext = forge_new LogContext("Global", err, true);
    }


    void deInit() {
        forge_del _GlobalStdOutContext;
        forge_del _GlobalErrOutContext;
        _GlobalStdOutContext = nullptr;
        _GlobalErrOutContext = nullptr;
    }


    OutStream &out() {
        return _GlobalStdOutContext->get_PassThroughStream();
    }


    OutStream &err() {
        return _GlobalErrOutContext->get_PassThroughStream();
    }


    bool isInitialized() { return _GlobalStdOutContext != nullptr && _GlobalErrOutContext != nullptr; }


    LogContext createLogContext(DynamicString userName,
                                OutStream stream,
                                bool mentionUser) {
        return LogContext(userName, stream, mentionUser);
    }

}   // namespace logging
}   // namespace forge
