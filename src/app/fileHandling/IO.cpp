// IO.cpp
#include <iostream>
#include "IO.hpp"
using namespace std;
IO::IO(const std::string& file_path) {
    file_stream.open(file_path, ios::in | ios::out | ios::binary);//opens a file in read+erite in binary mode
    if (!file_stream.is_open()) {
        cout << "Unable to open file: " << file_path << endl;//If opening fails, logs an error
    }
}

IO::~IO() {//Destructor: Closes the file if it’s still open, preventing resource leaks.
    if (file_stream.is_open()) {
        file_stream.close();
    }
}

    fstream IO::getFileStream() {
    return move(file_stream);
}

// file_stream is a special object that can’t be copied, only moved (like a pen — you can't duplicate it, only pass it).
// When you use std::move, you are transferring ownership — after that, the file_stream inside your IO object is empty or unusable.
// So, the IO object can’t do any more file operations after this.