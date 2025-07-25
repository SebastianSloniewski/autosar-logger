#ifndef ARA_LOG_COMMON_H
#define ARA_LOG_COMMON_H

#include <cstdint>
namespace ara{
namespace log{
    
enum class LogLevel : uint8_t {
    kOff        = 0,
    kFatal      = 1,
    kError      = 2,
    kWarn       = 3,
    kInfo       = 4,
    kDebug      = 5,
    kVerbose    = 6 
};

enum class LogMode : uint8_t {
    kRemote = 0x01,
    kFile   = 0x02,
    kConole = 0x04
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

} // log namespace
} // ara namespace

#endif // !ARA_LOG_COMMON_H