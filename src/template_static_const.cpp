
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

int main(int argc, char* argv[])
{
    return add<MyClass<int>::a>(argc);
}
