/*****************************

C++11 thread constructor 'decay_copies' the newly created thread's arguments.
See http://www.cplusplus.com/reference/type_traits/decay/

It s quite un-pleasant (however totally standard compliant) when you want to 
pass a (un-copyable) class by reference.
You can pass it by pointer with no problem.
Also if you wrap it in a by-reference lambda then it is OK

******************************/

#include <iostream>
#include <thread>

struct B
{
    B(int a) : a(a){}
    ~B(){}
    int a;
private:
    B(const B&){}
    B(B&&){}
};

void f(B& x)
{
    x.a *= 3;
}

void g(B* x)
{
    x->a *= 3;
}

int main(int argc, char* argv[])
{
    B b(argc);
    // std::thread t(g, &b); // OK
    std::thread t(f, b);
    t.join();
    t = std::thread([&](){f(b);}); // also OK
    t.join();
    return b.a;
}
