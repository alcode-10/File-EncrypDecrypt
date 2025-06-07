// IO.hpp
#ifndef IO_HPP
#define IO_HPP //Header guards: Prevent multiple inclusion of the same header during compilation

#include <fstream>
#include <string>

class IO {
public:
    IO(const std::string& file_path);//constructor,that takes a file path.
    ~IO(); //destructor,that closes the stream.
    std::fstream getFileStream(); //returns file stream,A getter to expose the stream (note: returned by std::move, so ownership is transferred).

private:
    std::fstream file_stream;//f_stream object name file_stream
};

#endif//closing of header guard