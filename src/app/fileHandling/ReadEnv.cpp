#include "IO.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class ReadEnv{
    public:
        std::string getenv(){
            std::string env_path = ".env";
            IO io(env_path);
            std::fstream f_stream = io.getFileStream();
            std::stringstream buffer;
            buffer << f_stream.rdbuf();
            std::string content = buffer.str();
            return content;
        }    
};

// Has one public method getenv(), which:

// Opens .env file using IO class.

// Transfers the stream into f_stream.

// Reads the file into a stringstream (reads entire file).

// Returns the contents as a string.

// 📌 This is useful for loading environment-like variables at runtime from a file.

