/*****************
VC 2017 compiles it
GCC 5.4.0 doesn't

gcc thinks that "t.g<b>" is an "operator<" between a member function and a bool
rather then template specialization.
Interesting enough if f is not a template then it compiles OK
******************/
struct C
{
    template<bool b>
    void g(int x){ x *= 2; }
};

template<bool b>
struct A
{
    template<typename C> // comment out this line for using the non-template C
    void f(C& t)
    {
        t.g<b>(0);
    }
};

int main()
{
    C c;
    A<true> a;
    a.f(c);
    return 0;
}
