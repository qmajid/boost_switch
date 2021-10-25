#include <output_queue.h>

OutputQueue* OutputQueue::my_queue = nullptr;
constexpr int QUEUE_SIZE = 500;

OutputQueue::OutputQueue(/* args */):
    queue(QUEUE_SIZE),
    is_finish(false),
    queue_count(0)
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
    ++queue_count;
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
            std::cout<<"----"<<value.c_str()<<"----"<<queue_count<<std::endl;
            //std::cout<<"----"<<value<<"----"<<std::endl;
            //usleep(1000*500);
            --queue_count;
        }
    }
    printf("end pop\n");
}

int OutputQueue::get_queue_count()
{
    return queue_count;
}