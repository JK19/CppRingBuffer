#include <RingBuffer.hpp>
#include <Snitch.hpp>
#include <utility>

using namespace ring;

int main(int argc, char const *argv[])
{

    RingBuffer<Snitch, 3> rb;

    std::cout << std::endl;

    std::cout << "///////////////////// T1 /////////////////////" << std::endl;
    Snitch s1;
    auto err = rb.put(std::move( s1 ));
    std::cout << "move insertion: " << err << std::endl;
    std::cout << "//////////////////////////////////////////////" << std::endl << std::endl;


    std::cout << "///////////////////// T2 /////////////////////" << std::endl;
    Snitch s2;
    err = rb.put( s2 );
    std::cout << "copy insertion: " << err << std::endl;
    std::cout << "//////////////////////////////////////////////" << std::endl << std::endl;


    std::cout << "///////////////////// T3 /////////////////////" << std::endl;
    Snitch s3;
    err = rb.put(std::move(s3));
    std::cout << "move insertion: " << err << std::endl;
    std::cout << "//////////////////////////////////////////////" << std::endl << std::endl;


    std::cout << "///////////////////// T4 /////////////////////" << std::endl;
    Snitch s4;
    err = rb.put(std::move(s4));
    std::cout << "should overflow: " << err << std::endl;
    std::cout << "//////////////////////////////////////////////" << std::endl << std::endl;


    std::cout << "///////////////////// T5 /////////////////////" << std::endl;
    Snitch s5;
    err = rb.get(s5);
    std::cout << "get call: " << err << std::endl;
    std::cout << "//////////////////////////////////////////////" << std::endl << std::endl;

    return 0;
}
