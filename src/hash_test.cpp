#include <unordered_map>
#include <string>

#ifdef  __GNUC__
namespace std {

// a bad hash, but at least a hash
template<class _Elem, class _Traits, class _Alloc>
struct hash<basic_string<_Elem, _Traits, _Alloc>>
{
    size_t operator()(const basic_string<_Elem, _Traits, _Alloc>& s) const noexcept
    {
		return (size_t)(*s.data());
    }
};

}

#endif

int main()
{
    std::unordered_map<std::basic_string<unsigned short>, size_t> mymap;
    return mymap.size();
}
