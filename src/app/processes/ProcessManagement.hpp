//processmanagement.hpp
#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>//task queue
#include <memory>//unique_ptr,something which will point to a location that cannt be accesed by antoher pointer.means is loaction copy cant be made
using namespace std;
class ProcessManagement
{
public:
    ProcessManagement();
    bool submitToQueue(unique_ptr<Task> task);
    void executeTasks();

private:
    queue<unique_ptr<Task>> taskQueue;//a queue of unique_ptr<Task>, owning the tasks.
};

#endif