#ifndef LOGGING_HPP
#define LOGGING_HPP

using namespace ara{
using namespace log{

class Logging{
public:
    static void InitLogging(
        std::string appId,
        std::string appDescription,
        LogLevel appDefLogLevel,
        LogMode logMode,
        std::string directoryPath
    ) noexcept;

    static Logger& CreateLogger(
        std::string ctxId,
        std::string ctxDescription
    ) noexcept;

    // Formatting helpers
    template<typename T> Argument<T> Hex(const T& value) noexcept;
    template<typename T> Argument<T> Oct(const T& value) noexcept;  
    template<typename T> Argument<T> Bin(const T& value) noexcept;
    template<typename T> Argument<T> Dec(const T& value) noexcept;

    }
} // log namespace
} // ara namespace

#endif // !LOGGING_HPP