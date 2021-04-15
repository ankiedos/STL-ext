#define MAIN_NS_BEGIN namespace stdext {
#define MAIN_NS_END }
#include<type_traits>
#include<initializer_list>

char DereferenceInitList(const std::initializer_list<char>& list) { return const_cast<char*>(list.begin())[0]; }
char DereferenceInitList(std::initializer_list<char>&& list) { return const_cast<char*>(std::move(list.begin()))[0]; }