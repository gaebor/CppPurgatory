#include <list>

/************************************************************************/
/* Const objects in stl containers                                      */
/************************************************************************/
/************************************************************************/
/* In Visual C++ it works                                               */
/* But in g++ I have never been able to make something like this work   */
/************************************************************************/

int main(int argc, char* argv[])
{
	std::list<const double> l;
	return l.size();
}