#include <unordered_map>
#include <map>

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