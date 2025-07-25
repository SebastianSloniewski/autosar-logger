#ifndef LOGGER_HPP
#define LOGGER_HPP 

 // .h zamienić na c<nazwa_biblioteki>
#include <stdint.h>
#include "logStream.hpp"

namespace ara{
namespace log{

class Logger{

public:
    
    Logger() = delete;
    ~Logger() noexcept;

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    //Log*() functions - creates unnamed LogStream objects
    LogStream LogFatal()    const noexcept;
    LogStream LogError()    const noexcept;
    LogStream LogWarn()     const noexcept;
    LogStream LogInfo()     const noexcept;
    LogStream LogDebug()    const noexcept;
    LogStream LogVerbose()  const noexcept;

private: 

    const std::string appId;
    const std::string appDescription;

    const std::string ctxId;
    const std::string ctxDescription;
    const LogLevel logLevel;

    const LogMode logMode;

};
}
}

#endif