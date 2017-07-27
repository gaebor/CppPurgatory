#include <functional>
#include <math.h>
#include <iostream>

int main(int argc, char** argv)
{
    std::function<float(float)> f;
#ifndef _MSC_VER
    f = exp2; // works for gcc (cl error: C2440, note: constructor overload resolution was ambiguous)
    std::cout << f((float)argc) << " ";
#endif
    f = (float(*)(float))exp2; // works for VS2015 but wrong in GCC
    std::cout << f((float)argc) << std::endl;

    return 0;
}
