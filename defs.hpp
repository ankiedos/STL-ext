#define MAIN_NS_BEGIN namespace stdext {
#define MAIN_NS_END }
#include<type_traits>
#include<initializer_list>

#define STDEXT_TEMPLATE_SFINAE_INTEGRAL(T) template<typename T, std::enable_if_t<std::is_integral_v<T>>>
#define LIBXX_TEMPLATE_SFINAE_INTEGRAL(T) STDEXT_TEMPLATE_SFINAE_INTEGRAL(T) // For backward compatibility

#define STDEXT_DECLARE_FUNCTION_BYVAL_BYREF_BYCONSTREF_BY_RVREF(helpers, base_rettype, header_without_rettype, body) \
helpers \
base_rettype header_without_rettype \
{ \
    body \
} \
helpers \
bas_rettype& heder_without_rettype \
{ \
    body \
} \
helpers \
const base_rettype& header_without_rettype \
{ \
    body \
} \
helpers \
base_rettype&& header_without_rettype \
{ \
    body \
}
char DereferenceInitList(const std::initializer_list<char>& list) { return const_cast<char*>(list.begin())[0]; }
char DereferenceInitList(std::initializer_list<char>&& list) { return const_cast<char*>(std::move(list.begin()))[0]; }