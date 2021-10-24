#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <boost/asio/thread_pool.hpp>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

#include <parser.h>
#include <string>

class ThreadPool
{
public:
    ~ThreadPool();
    explicit ThreadPool(int thread_count);
    void print();
    void init();
    void assign_task(std::string input);
    boost::asio::thread_pool& get_pool();

private:
    int thread_count;
    boost::asio::thread_pool pool;   
};

#endif