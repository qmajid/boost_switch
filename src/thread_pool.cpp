#include <iostream>

#include "thread_pool.h"

ThreadPool::ThreadPool(int thread_count) :
    thread_count(thread_count),
    pool(thread_count)
{
}

ThreadPool::~ThreadPool()
{
    printf("ThreadPool::~ThreadPool()\n");
}

boost::asio::thread_pool& ThreadPool::get_pool()
{
    return pool;
}

void ThreadPool::print()
{
    std::cout << "thread_count is:" <<thread_count<< std::endl;
}

void ThreadPool::init()
{
    // Launch the pool with four threads.
    // boost::asio::thread_pool pool(thread_count);
}

void ThreadPool::assign_task(std::string input)
{
    // Submit a function to the pool.
    boost::asio::post(pool, std::bind(parser::print, input));
}