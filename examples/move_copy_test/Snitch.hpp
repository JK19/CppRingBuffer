#if !defined(SNITCH_H)
#define SNITCH_H

#include <iostream>

class Snitch
{
private:
    void Log(std::string&& x) {
        std::cout << x << std::endl;
    }

public:
    
    Snitch() 
    {
        Log("Snitch]> Empty constructor");
    }

    Snitch(const Snitch& other)
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
