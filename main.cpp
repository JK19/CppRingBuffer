#include <RingBuffer.hpp>
#include <Snitch.hpp>
#include <utility>
#include <deque>
#include <vector>
#include <array>

using namespace ring;

int main(int argc, char const *argv[])
{
    


    
    using Snitch = Snitch<27>;

    RingBuffer<Snitch, 3> rb;

    Log("///////////////////// T1 /////////////////////")
    Snitch s1;
    auto err = rb.put(std::move( s1 ));
    Log("insercion por movimiento: " << err);
    Log("//////////////////////////////////////////////" << std::endl);

    Log("///////////////////// T2 /////////////////////")
    Snitch s2;
    err = rb.put( s2 );
    Log("insercion por copia: " << err);
    Log("//////////////////////////////////////////////" << std::endl);


    Log("///////////////////// T3 /////////////////////")
    Snitch s3;
    err = rb.put(std::move(s3));
    Log("insercion por movimiento: " << err);
    Log("//////////////////////////////////////////////" << std::endl);


    Log("///////////////////// T4 /////////////////////")
    Snitch s4;
    err = rb.put(std::move(s4));
    Log("should overflow: " << err);
    Log("//////////////////////////////////////////////" << std::endl);


    Log("///////////////////// T5 /////////////////////")
    Snitch s5;
    err = rb.get(s5);    
    Log("get call: " << err);
    Log("//////////////////////////////////////////////" << std::endl);
    

    return 0;
}
