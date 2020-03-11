/*
For some reason Visual Studio doesn't compile this
But if I initialize MyClass::a inside the class definition (not just forward declare it)
then VS compiles it.
*/

template<class Ty>
struct MyClass
{
    static const int a;
};

template<class Ty>
const int MyClass<Ty>::a = sizeof(Ty);

template<int x>
int add(int y)
{
    return x + y;
}

int main(int argc, const char**)
{
    return add<MyClass<int>::a>(argc);
}
