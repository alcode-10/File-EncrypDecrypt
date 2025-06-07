#include <iostream>
#include <filesystem>
#include "./src/app/processes/ProcessManagement.hpp"
#include "./src/app/processes/Task.hpp"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    std::string path;
    std::string action;

    std::cout << "Enter the file or directory path: ";
    std::getline(std::cin, path);

    std::cout << "Enter the action (encrypt/decrypt): ";
    std::getline(std::cin, action);

    try {
        if (fs::exists(path)) {
            ProcessManagement processManagement;

            if (fs::is_directory(path)) {
                for (const auto& entry : fs::recursive_directory_iterator(path)) {
                    if (entry.is_regular_file()) {
                        std::string filePath = entry.path().string();
                        IO io(filePath);
                        std::fstream f_stream = std::move(io.getFileStream());

                        if (f_stream.is_open()) {
                            Action taskAction = (action == "encrypt") ? Action::ENCRYPT : Action::DECRYPT;
                            auto task = std::make_unique<Task>(std::move(f_stream), taskAction, filePath);
                            processManagement.submitToQueue(std::move(task));
                        } else {
                            std::cout << "Unable to open file: " << filePath << std::endl;
                        }
                    }
                }
            } else if (fs::is_regular_file(path)) {
                IO io(path);
                std::fstream f_stream = std::move(io.getFileStream());

                if (f_stream.is_open()) {
                    Action taskAction = (action == "encrypt") ? Action::ENCRYPT : Action::DECRYPT;
                    auto task = std::make_unique<Task>(std::move(f_stream), taskAction, path);
                    processManagement.submitToQueue(std::move(task));
                } else {
                    std::cout << "Unable to open file: " << path << std::endl;
                }
            }

            processManagement.executeTasks();
        } else {
            std::cout << "Invalid path! Please enter a valid file or directory." << std::endl;
        }
    } catch (const fs::filesystem_error& ex) {
        std::cout << "Filesystem error: " << ex.what() << std::endl;
    }

    return 0;
}
