template<class Type>
struct Struct
{
    int a(int x){return x } // syntax error
    int b(int y){return y;}
};

int main()
{
    return Struct<void>().b(0);
}
