/************************************************************************/
/* this is just a demo for various pointer types                        */
/*                                                                      */
/* featuring:                                                           */
/* pointer to member function                                           */
/* pointer to a member which is a function pointer                      */
/* pointer to a static member function                                  */
/* and all of these in an array                                         */
/************************************************************************/

struct MyClass
{
    int i;
    int f(int x)const { return i + x; }
    static int g(int x) { return 2 * x; }
    int(*t1)(int);
    int(*t2)(int);
};

int function1(int x)
{
    return 3 * x + 1;
}

int function2(int x)
{
    return x / 2;
}

int main(int, char*[])
{
    MyClass testClass;
    testClass.i = 7;
    testClass.t1 = function1;
    testClass.t2 = function2;

    int(*MyClass::*x)(int) = &MyClass::t1;
    int(*MyClass::*xx[])(int) = { &MyClass::t1, &MyClass::t2, &MyClass::t2 };
    int(MyClass::*yy[])(int) const = { &MyClass::f, &MyClass::f };
    int(*zz[])(int) = { &MyClass::g, function1 };
    
    return (testClass.*(yy[1]))(0) + (testClass.*(xx[2]))(0) + (zz[0])(0);
    // should return 7
}
