// Task.hpp
#ifndef TASK_HPP
#define TASK_HPP // header guard to prevent inclusion of file

#include "../fileHandling/IO.hpp" //custom file handling class (handles file streams).
#include <fstream>
#include <string>
#include <sstream> // (used for parsing/serializing strings).

enum class Action
{ // Defines an enumeration Action with two values: ENCRYPT and DECRYPT.
  // This helps to specify what the task should do with the file.
    ENCRYPT,
    DECRYPT
};

struct Task
{
    std::string filePath;
    std::fstream f_stream;
    Action action;
    // Defines a struct Task representing one task:
    // filePath: path of the file to encrypt/decrypt.
    // f_stream: the file stream opened on that file.
    // action: what operation to perform (encrypt or decrypt).

    Task(std::fstream &&stream, Action act, std::string filePath) : f_stream(std::move(stream)), action(act), filePath(filePath) {}
    // rvalue reference to fstream,
    // Initializes the member variables, moving the stream into f_stream
    std::string toString() const
    {
        std::ostringstream oss;                                                        // Uses ostringstream to build the string.
        oss << filePath << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT"); // Converts a Task into a string in format: "filePath,ENCRYPT" or "filePath,DECRYPT".
        return oss.str();
    }

    static Task fromString(const std::string &taskData) // Static method to create a Task from a string.
    {
        std::istringstream iss(taskData); // Takes the input string taskData.
        std::string filePath;// Uses istringstream to parse it.
        std::string actionStr; // Defines two strings: one for filePath and one for actionStr.
        if (std::getline(iss, filePath, ',') && std::getline(iss, actionStr))//first path to file path and other to actionstr
        {
            Action action = (actionStr == "ENCRYPT") ? Action::ENCRYPT : Action::DECRYPT;//converted to enum value,the encrypt and decrypt
            IO io(filePath);//IO object
            std::fstream f_stream = std::move(io.getFileStream());//moves returned stream to f_stream,a fstream is returned on calling which is stored here
            if (f_stream.is_open())
            {
                return Task(std::move(f_stream), action, filePath);//return new task with all parameters
            }
            else
            {
                throw std::runtime_error("Failed to open file: " + filePath);
            }
        }
        else
        {
            throw std::runtime_error("Invalid task data format");
        }
    }
};

#endif