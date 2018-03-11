#include <map>
// see https://stackoverflow.com/questions/44699545/why-does-stdmap-emplace-need-a-copy-constructor-on-gcc

class CMyClass
{
public:
  CMyClass(int) {};
private:
  CMyClass(const CMyClass&); // I want to avoid copy construction
};

int main()
{
  std::map<int, CMyClass> mymap;
  mymap.emplace(0, 0);

  return 0;
}
