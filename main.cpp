#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>

#include <boost/atomic.hpp>

#include <thread_pool.h>
#include <Hello.h>
#include <output_queue.h>

#include <string>

boost::atomic_int producer_count(0);
boost::atomic_int consumer_count(0);

boost::lockfree::queue<int> queue(128);

const int iterations = 10000000;
const int producer_thread_count = 4;
const int consumer_thread_count = 4;

void producer(void)
{
    for (int i = 0; i != iterations; ++i) {
        int value = ++producer_count;
        std::cout<<"push:"<<value<<std::endl;
        while (!queue.push(value))
            ;
    }
}

boost::atomic<bool> done (false);
void consumer(void)
{
    int value;
    while (!done) {
        while (queue.pop(value))
        {
            ++consumer_count;
            std::cout<<"!done pop:"<<consumer_count<<std::endl;
        }
    }

    while (queue.pop(value))
    {
        ++consumer_count;
        std::cout<<"pop:"<<consumer_count<<std::endl;
    }
}

void start_consumer(void)
{
    OutputQueue::get_instance()->pop();
}

int main(int argc, char* argv[])
{
    using namespace std;

    OutputQueue* output_queue = OutputQueue::get_instance();
    boost::thread pop_thread{start_consumer};
    ThreadPool* tp = new ThreadPool(10);
    for(int i=0; i<100000; ++i)
    {
        tp->assign_task(std::to_string(i));

        while (output_queue->get_queue_count() > 100)
        {
            printf("usleep %d\n", output_queue->get_queue_count());
            usleep(1000);
        }
        // if (i>0 && i%5000 == 0)
        //     usleep(1000*1000*5);
    }
    tp->assign_task("majid");
    tp->assign_task("hamid");
    tp->assign_task("hasan");
    tp->assign_task("hossein");

    printf("a\n");
    tp->get_pool().join();
    printf("b\n");
    OutputQueue::get_instance()->terminate();
    printf("c\n");
    pop_thread.join();
    printf("d\n");
    return 0;








    cout << "boost::lockfree::queue is ";
    if (!queue.is_lock_free())
        cout << "not ";
    cout << "lockfree" << endl;

    boost::thread_group producer_threads, consumer_threads;

    for (int i = 0; i != producer_thread_count; ++i)
        producer_threads.create_thread(producer);

    for (int i = 0; i != consumer_thread_count; ++i)
        consumer_threads.create_thread(consumer);

    producer_threads.join_all();
    done = true;

    consumer_threads.join_all();

    cout << "produced " << producer_count << " objects." << endl;
    cout << "consumed " << consumer_count << " objects." << endl;
}