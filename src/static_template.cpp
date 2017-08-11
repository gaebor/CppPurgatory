
template<class X>
struct Y
{
	static X x;
};

// g++ error: specializing member requires ‘template<>’ syntax
// in Visual C++ it is allowed
int Y<int>::x = 0;

int main()
{
	Y<int> y;
	return Y<int>::x;
}
