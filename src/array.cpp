/************************************************************************/
/* allocate an array with run-time-given length                          */
/************************************************************************/
/************************************************************************/
/* in gcc you just can do that                                          */
/* however in Visual C++ you can't                                      */
/*                                                                      */
/* this is not C++ specific, the behaviour is the same in C             */
/************************************************************************/

int main(int argc, char* argv[])
{
	int a[argc];
	a[0] = 0;
	return a[0];
}
