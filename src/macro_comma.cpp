/************************************************************************/
/* demonstrates the preprocessor mechanism                              */
/*                                                                      */
/* it won't compile, due to the comma in the template argument          */
/* preprocessor thinks that this is macro with three arguments          */
/* Note that the second line works!                                     */
/*                                                                      */
/* this should return 4, which is sizeof(int)                           */
/************************************************************************/

#include <stddef.h>

template<class Type1, class Type2>
struct CompoundType
{
    Type1 t1;
    Type2 t2;
};

typedef CompoundType<int, char> MyType;

int main(int, char*[])
{
    return offsetof(CompoundType<int, char>, t2);
    // return offsetof(MyType, t2);
}
