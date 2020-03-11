/*
static variable in a constexpr method.

GCC 5.4 says:
error: ‘mask1’ declared ‘static’ in ‘constexpr’ function

Visual Studio 17 compiles it.
*/

template<int width>
struct Round
{
    template<class Number>
    static constexpr Number Do(Number i)
    {
        static const Number mask1 = width - 1;
        static const Number mask2 = ~mask1;
        return (i + mask1) & mask2;
    }
};

int main(int argc, const char**)
{
    return Round<4>::Do<int>(argc);
}