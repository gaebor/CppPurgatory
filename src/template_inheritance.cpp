/************************************************************************/
/* Member offset is inherited from AbstractClass                        */
/*                                                                      */
/* In Visual C++ it compiles.                                           */
/* In g++ it doesn't                                                    */
/* but if you replace the function Get with the static version          */
/* then it is OK                                                        */
/* just remove the definition of Get and use the second row in main     */
/*                                                                      */
/* The behaviour is the same for non-static members                     */
/*  inherited from a template class                                     */
/* the compiler just doesn't see the inherited member                   */
/************************************************************************/

#include <stddef.h>

template<typename T>
struct AbstractClass
{
    typedef T MyType;
    static const size_t offset = sizeof(MyType);
};

template<typename T>
struct ChildClass : AbstractClass<T*>
{
    static size_t Get()
    {
        return offset; // this->offset
    }
};

int main(int argc, char* argv[])
{
    return ChildClass<char>::Get();
    // return ChildClass<char>::offset;
}