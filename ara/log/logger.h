#ifndef LOGGER_HPP
#define LOGGER_HPP 

#include <stdint.h>
#include "logStream.hpp"

namespace ara{
namespace log{

enum class LogLevel : uint8_t {
    kOff,
    kFatal,
    kError,
    kWarn,
    kInfo,
    kDebug,
    kVerbose
};

enum class LogMode : uint8_t {
    kRemote,
    kFile,
    kConole
};

void InitLogging(
    std::string appId,
    std::string appDescription,
    LogLevel appDefLogLevel,
    LogMode logMode,
    std::string directoryPath
) noexcept;

Logger& CreateLogger(
    std::string ctxId,
    std::string ctxDescription
) noexcept;

class Logger{

public:
    bool IsLogEnabled();

    //Log*() functions - creates unnamed LogStream objects
    LogStream LogFatal();
    LogStream LogError();
    LogStream LogWarn();
    LogStream LogInfo();
    LogStream LogDebug();
    LogStream LogVerbose();

private:
    std::vector<LogStream> streams;   
    const std::string appId;
    const std::string appDescription;
    const std::string ctxId;
    const std::string ctxDescription;
    const LogLevel logLevel;
    const LogMode logMode;

    std::string _logLevelToString(LogLevel logLevel);

};
}
}

#endif