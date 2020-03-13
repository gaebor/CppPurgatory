// see https://github.com/MicrosoftDocs/cpp-docs/issues/1981

#include<cstdio>

template<int i>
void f()
{
    if (i == 0)
        std::puts("f zero");
    else
        std::puts("f positive");
}

int main()
{
    f<0>();
    f<1>();
	return 0;
}
