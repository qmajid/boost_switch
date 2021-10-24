#include <parser.h>
#include <unistd.h>
#include <output_queue.h>

parser::parser(/* args */)
{

}

parser::~parser()
{
}

void parser::print(std::string msg)
{
    //std::cout<<"----"<<msg<<"----"<<std::endl;
    OutputQueue::get_instance()->push(msg);
}