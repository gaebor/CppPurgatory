#include <list>

/************************************************************************/
/* Const objects in stl containers                                      */
/************************************************************************/
/************************************************************************/
/* In Visual Studio 2013 it works                                       */
/* In g++ , it doesn't                                                  */
/* As @ngg pointed out, this is forbidden per standard.                 */
/* I don't know why Visual Studio allowed it,                           */
/* but in Visual Studio 2013 it is forbidden                            */
/************************************************************************/

int main(int argc, char* argv[])
{
	std::list<const double> l;
	return l.size();
}