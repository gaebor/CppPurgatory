/************************************************************************/
/* order of template resolution                                         */
/************************************************************************/
/************************************************************************/
/* template class A uses B, but B is defined later                      */
/* Visual C++ can compile it                                            */
/* gcc cannot                                                           */
/************************************************************************/

template<class C>
struct A
{
	static int Do()
	{
		return B<C>::Do();
	}
};

template<class C>
struct B
{
	static int Do()
	{
		return 0;
	}
};

int main(int, char*[])
{
	return A<int>::Do();
}
