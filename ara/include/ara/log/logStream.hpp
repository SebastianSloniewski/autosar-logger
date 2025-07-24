#ifndef LOGSTREAM_HPP
#define LOGSTREAM_HPP


#include "logging.h"
namespace ara{ 
namespace log{
class LogStream{
    public:

    LogStream();
    ~LogStream();

    // Overload << for any type
    template<typename T>
    LogStream& operator<<(const T& value) {
        _buffer << value;
        return *this;
    }

    void Flush();

    private:
    const std::string appId;
    const std::string ctxId;
    const std::string logLevel;
    std::ostringstream _buffer;
    std::ostream* _out; //std::cout na razie
    LogLevel logLevel;


    void setOutput(std::ostream* out);
};
}
}
#endif