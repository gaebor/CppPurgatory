#include <map>

int main(int argc, char* argv[])
{
	std::map<int, int> m;
	m[0] = m.size();
	return m[0];
}