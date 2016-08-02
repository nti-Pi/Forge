#ifndef __HG__FORGE__LOGGING_HPP__
#define __HG__FORGE__LOGGING_HPP__

#include "logging/LogContext.hpp"
#include "structures/io/OutStream.hpp"

#include "structures/DString.hpp"


namespace forge {
namespace logging {

    using namespace structures;
    using namespace structures::io;

    void init(OutStream out, OutStream err);
    void deInit();

    OutStream &out();
    OutStream &err();

    bool isInitialized();

    LogContext createLogContext(DString userName,
                                OutStream stream,
                                bool mentionUser = false);

}   // namespace logging
}   // namespace forge


#endif // __HG__FORGE__LOGGING_HPP__
