#ifndef LOGSTREAM_HPP
#define LOGSTREAM_HPP


#include "logging.h"
namespace ara{ 
namespace log{

template<typename T>

class LogStream{
    public:

    LogStream();
    ~LogStream();

    // Overload << for any type

    LogStream& operator<<(const T& value);

    void Flush();
    void setOutput(std::ostream* out);

    private:
    std::ostringstream _buffer;
    std::ostream* _out;
    LogLevel logLevel;
};
}
}
#endif