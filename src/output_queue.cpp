#include <output_queue.h>

OutputQueue* OutputQueue::my_queue = nullptr;

OutputQueue::OutputQueue(/* args */):
    queue(128),
    is_finish(false)
{
}

OutputQueue::~OutputQueue()
{
}

OutputQueue* OutputQueue::get_instance()
{
    if (my_queue)
    {
        return my_queue;
    }

    my_queue = new OutputQueue();
    return my_queue;
}

void OutputQueue::terminate()
{
    is_finish = true;
}

void OutputQueue::push(string message)
{
    //printf("push");
    while (!queue.push(message.c_str()));  
}

string OutputQueue::pop()
{
    printf("start pop\n");
    string value;
    while(!is_finish)
    {
        while (queue.pop(value))
        {
            std::cout<<"----"<<value<<"----"<<std::endl;
        }
    }
    printf("end pop\n");
    return value;
}