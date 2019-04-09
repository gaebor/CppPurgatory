/*****************************************************
This is actually the same in Visual C++ and GCC
but it is interesting

Inside a member function when a member has the same name as a function parameter
then the member attribute has a lower precedence than the function parameter
*****************************************************/

#include <iostream>
#include <vector>
#include <utility>

struct Class
{
    Class()
    {
        std::cout << "Constructor\t" << this << std::endl;
    }
    Class(const Class& other)
    {
        std::cout << "Copy\t" << this << std::endl;
    }
    Class(Class&& other)
    {
        std::cout << "Move\t"  << this << std::endl;
    }
    ~Class()
    {
        std::cout << "Destructor\t" << this << std::endl;
    }
};

int main()
{
    // constructor without destructor (memory leak)
    Class* c = new Class(); 
    
    std::vector<Class> v;
    
    // proper constructor and destructor will be called (stack variable)
    Class a;
    
    // the new element is swapped with 'a', but 'a' is swapped with an un-initialized object
    // later, when 'a' is destructed, the un-initialized object is destructed
    // destructor is called without any constructor (!)
    v.emplace_back(std::move(a)); 
    
    return 0;
}
