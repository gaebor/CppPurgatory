/***********************************************
Strange behavior of static_cast

If I cast a nullptr, then it stays nullptr,
but if I cast anything greater, then it casts well!

Is this documented somewhere?
(it is the same in GCC and Visual C++)
***********************************************/

#include<iostream>

struct A
{
    int a;
};

struct B
{
    int b;
};

struct C : A, B
{};

int main()
{    
    C* cp = nullptr;
    std::cout << (size_t)static_cast<B*>(cp) - (size_t)cp << std::endl;
    
    cp++;
    std::cout << (size_t)static_cast<B*>(cp) - (size_t)cp << std::endl;
    
    C c;
    cp = &c;
    std::cout << (size_t)static_cast<B*>(cp) - (size_t)cp << std::endl;
    
    return 0;
}
