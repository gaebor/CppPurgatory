#include <unordered_map>
#include <map>
/************************************************************************/
/* A class uses itself as a member                                      */
/************************************************************************/
/************************************************************************/
/* See how MyClass appears inside its own definition                    */
/*                                                                      */
/* In Visual C++ it just compiles.                                      */
/* Interesting enough, in g++ it doesn't                                */
/* but if you replace unordered_map with map, then it is OK             */
/************************************************************************/

class MyClass
{
public:
	std::unordered_map<int, MyClass> others;
	char a;
};

int main(int argc, char* argv[])
{
	MyClass myinstance;
	return myinstance.others.size();
}