#ifndef LOGSTREAM_HPP
#define LOGSTREAM_HPP


#include "ara/log/common.h"
#include "common.h"
#include "logger.h"
#include <sstream>
#include <memory>

namespace ara{ 
namespace log{
class LogStream{
    public:

    LogStream(LogLevel lvl, Logger* owner) noexcept;
    ~LogStream() noexcept;

    // Overload << for any type
    template<typename T>
    LogStream& operator<<(const T& value) {
        _buffer << value;
        return *this;
    }

    void Flush() noexcept;

    private:
    LogLevel   level_;
    Logger*    logger_;
    std::ostringstream buffer_;


    void setOutput(std::ostream* out);
};
}
}
#endif