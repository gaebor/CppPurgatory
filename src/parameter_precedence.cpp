/*****************************************************
This is actually the same in Visual C++ and GCC
but it is interesting

Inside a member function when a member has the same name as a function parameter
then the member attribute has a lower precedence than the function parameter
*****************************************************/

#include <iostream>

struct Class
{
    int i;
    Class(int i): i(i) {}
    void f(int i)
    {
        std::cout << i << " " << this->i << std::endl;
    }
};

int main()
{
    Class c(0);
    c.f(3);
    return 0;
}
