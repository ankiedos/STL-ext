#define MAIN_NS_BEGIN namespace stdext {
#define MAIN_NS_END }
#include<type_traits>
#include<initializer_list>

#define LIBXX_TEMPLATE_SFINAE_INTEGRAL(T) template<typename T##, std::enable_if_t<std::is_integral_v<##T##>>>

char DereferenceInitList(const std::initializer_list<char>& list) { return const_cast<char*>(list.begin())[0]; }
char DereferenceInitList(std::initializer_list<char>&& list) { return const_cast<char*>(std::move(list.begin()))[0]; }