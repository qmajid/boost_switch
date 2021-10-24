#ifndef __OUTPUT_QUEUE_H__
#define __OUTPUT_QUEUE_H__

#include <string>
#include <unistd.h>
#include <iostream>

#include <boost/lockfree/queue.hpp>

using namespace std;

class OutputQueue
{
public:
    ~OutputQueue();
    static OutputQueue* get_instance();
    void terminate();
    void push(string message);
    string pop();

private:
    OutputQueue();
    static OutputQueue* my_queue;
    boost::lockfree::queue<const char*> queue;
    bool is_finish;
};



#endif