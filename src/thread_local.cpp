/*********************************************
This program starts several threads
and initializes a thread-local variable in all of them.

C++11 standard permits this.
in VS2013 you get
    error C2483: object with constructor or destructor cannot be declared 'thread'
in VS2017 it works fine!
*********************************************/

#include <vector>
#include <iostream>
#include <thread>
#include <memory>

#ifdef _MSC_VER
#   define thread_local __declspec(thread)
#endif

struct B
{
    B(){ i = 0; std::cout << "Constructor!" << std::endl; }
    int i;
    ~B(){ std::cout << "Destructor!" << std::endl; }
};

thread_local B b;

int main(int argc, char* argv[])
{
    std::vector<std::shared_ptr<std::thread>> threads;
    b.i += 1;
    for (int i = 0; i < argc; ++i)
    {
        threads.emplace_back(new std::thread([](){std::cout << b.i << std::endl;}));
    }
    for (int i = 0; i < argc; ++i)
        threads[i]->join();
    
    std::cout << b.i << std::endl;
    
    return 0;
}
