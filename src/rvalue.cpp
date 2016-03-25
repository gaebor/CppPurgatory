/************************************************************************/
/* assigning an rvalue to a reference                                   */
/************************************************************************/
/************************************************************************/
/* As far as I know, assigning an rvalue to a reference                 */
/* calls a copy constructor.                                            */
/* In row 21, everything works fine,                                    */
/* but in row 22, an extra copy constructor is called                   */
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
