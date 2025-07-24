#ifndef ARA_LOG_COMMON_H
#define ARA_LOG_COMMON_H

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

} // log namespace
} // ara namespace

#endif // !ARA_LOG_COMMON_H