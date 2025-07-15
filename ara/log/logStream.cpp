#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

using namespace ara::log;   

class LogStream {
public:

    LogStream(std::ostream* out = &std::cout) : _out(out) {}

    template<typename T>
    LogStream& operator<<(const T& value) {
        _buffer << value;
        return *this;
    }

    ~LogStream() {
        if (_out) {
            *_out << _buffer.str() << std::endl;
        }
    }

    void Flush() {
        if (_out) {
            *_out << _buffer.str() << std::endl;
            _buffer.str("");
            _buffer.clear();
        }
    }

    void setOutput(std::ostream* out) {
        _out = out;
    }

private:
    std::ostringstream _buffer;
    std::ostream* _out;
};