#include <map>

/************************************************************************/
/* Operator order                                                       */
/************************************************************************/
/************************************************************************/
/* As you may know, the following is __undefined behaviour__            */
/* my_function(i, i++, --i)                                             */
/*                                                                      */
/* In Visual C++ it is always "from right to left":                     */
/* --i                                                                  */
/* i++                                                                  */
/* and then                                                             */
/* my_function                                                          */
/*                                                                      */
/* In g++ this very example returns 1                                   */
/* In Visual C++ this returns 0                                         */
/************************************************************************/
/************************************************************************/
/* REMEDY not the same thing but you may want something like this:      */
/*                                                                      */
/* m.emplace(0, m.size());                                              */
/************************************************************************/

int main(int argc, char* argv[])
{
	std::map<int, int> m;
	m[0] = m.size();
	return m[0];
}