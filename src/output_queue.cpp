#include <output_queue.h>

OutputQueue* OutputQueue::my_queue = nullptr;
constexpr int QUEUE_SIZE = 500;

OutputQueue::OutputQueue(/* args */):
    queue(QUEUE_SIZE),
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
    //printf("push:%s\n", message.c_str());
    while (!queue.push(message.c_str()));
}

void OutputQueue::pop()
{
    printf("start pop\n");
    while(!is_finish)
    {
        //printf("!is_finish\n");
        string value = "";
        while (queue.pop(value))
        {
            printf("----%s----\n", value.c_str());
            //std::cout<<"----"<<value<<"----"<<std::endl;
            //usleep(100*5);
        }
    }
    printf("end pop\n");
}