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

thread_local B b; //error C2483: object with constructor or destructor cannot be declared 'thread'

int main(int argc, char* argv[])
{
    std::vector<std::shared_ptr<std::thread>> threads;
    for (int i = 0; i < argc; ++i)
    {
        threads.emplace_back(new std::thread([](){std::cout << b.i << std::endl;}));
    }
    for (int i = 0; i < argc; ++i)
        threads[i]->join();

    return 0;
}
