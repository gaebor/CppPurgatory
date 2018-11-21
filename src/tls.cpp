/********************************************
thread local storage
See https://stackoverflow.com/q/24253584/3583290

In Visual C++ (MSC_VER >= 1900) the thread variables are initialized
upon thread creation.
While in gcc, they are initialized when odr-used

try "tls" and "tls 1"
********************************************/

#include <iostream>
#include <thread>

using namespace std;

struct C
{
  C() { cout << "C constructor\n";}
  ~C() { cout << "C destructor\n";}
};

thread_local C foo;

int main(int argc, char** argv)
{
    if (argc > 1)
        foo;
    if (argc > 1)
    {
        std::thread t([](){foo;});
        t.join();
    }

    return 0;
}
