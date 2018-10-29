#include <cstdlib>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <typeinfo>

/**
 * Run time solution as per SO user "Howard Hinnant"
 * https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c
 */
template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

/**
 * Compile time solution as per SO user "Jamboree"
 * https://stackoverflow.com/questions/35941045/can-i-obtain-c-type-names-in-a-constexpr-way/35943472#35943472
 */
struct string_view
{
    char const* data;
    std::size_t size;
};

inline std::ostream& operator<<(std::ostream& o, string_view const& s)
{
    return o.write(s.data, s.size);
}

template<class T>
constexpr string_view get_name()
{
    char const* p = __PRETTY_FUNCTION__;
    while (*p++ != '=');
    for (; *p == ' '; ++p);
    char const* p2 = p;
    int count = 1;
    for (;;++p2)
    {
        switch (*p2)
        {
        case '[':
            ++count;
            break;
        case ']':
            --count;
            if (!count)
                return {p, std::size_t(p2 - p)};
        }
    }
    return {};
}
