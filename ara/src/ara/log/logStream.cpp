#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "logStream.hpp"

using namespace ara::log;   

LogStream::LogStream(std::ostream* out = &std::cout) : _out(out) {}

LogStream::~LogStream() {
    if (_out) {
        *_out << _buffer.str() << std::endl;
    }
}

void LogStream::Flush() {
    if (_out) {
        *_out << _buffer.str() << std::endl;
        _buffer.str("");
        _buffer.clear();
    }
}

void LogStream::setOutput(std::ostream* out) { //should be private
    _out = out;
}