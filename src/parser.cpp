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
    usleep(1*1);
    //std::cout<<"----"<<msg<<"----"<<std::endl;
    OutputQueue::get_instance()->push(msg);
}

// void parser::print()
// {
//     std::cout<<"default parser..."<<std::endl;
// }