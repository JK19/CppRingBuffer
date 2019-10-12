#if !defined(SNITCH_H)
#define SNITCH_H

#include <iostream>
#define Log(x) std::cout << x << std::endl;

template<std::size_t TSize>
class Snitch
{
private:

public:
    
    Snitch() 
    {
        //Log("Snitch]> Empty constructor");
        std::cout << "Snitch]> Empty constructor with template param: " << TSize << std::endl;
    }

    SnitchSnitch(const Snitch& other)
    {
        Log("Snitch]> Copy constructor");
    }

    Snitch& operator=(const Snitch& other)
    {
        Log("Snitch]> Copy assignment");
    }

    Snitch(Snitch&& other)
    {
        Log("Snitch]> Move constructor");
    }

    Snitch& operator=(Snitch&& other)
    {
        Log("Snitch]> Move assignment");
    }

    ~Snitch()
    {
        Log("Snitch]> Destructor called");
    }

};



#endif // SNITCH_H
