/************************************************************************/
/* assigning an rvalue to a reference                                   */
/************************************************************************/
/************************************************************************/
/* As far as I know, assinging an rvalue to a reference                 */
/* calls a copy constructor.                                            */
/* In row 19, everything works fine,                                    */
/* but in row 20, an extra copy constructor is called                   */
/* with gcc, this won't compile                                         */
/************************************************************************/

int& increment(int &x)
{
	++x;
	return x;
}

int main(int argc, char* argv[])
{
	int x = 0;
	int y = increment(x);
	y = increment(int(x));
	return y;
}
