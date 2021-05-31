#pragma once
#include<../../temp_lib.hpp>
#include<algorithm>

MAIN_NS_BEGIN
namespace Algorithms
{
    STDEXT_DECLARE_FUNCTION_BYVAL_BYREF_BYCONSTREF_BY_RVREF(template<typename Container>
    requires Concepts::InterableContainer<Container> && Concepts::CopyConstructible<Container>,
    Container, BubbleSort(const Container& cont),
    Container res{cont};
    bool sorted{false};
    for(auto i : res)
    {
        if(i == std::end(cont) || i + 1 == std::end(cont)) break;
        if(*i == *(i + 1)) continue;
        if(*i < *(i + 1)) sorted = true; else sorted = false;
    }
    if(sorted) return res;
    sort:
    for(auto i : res)
    {
        if(i == std::end(cont) || i + 1 == std::end(cont)) break;
        if(*i == *(i + 1)) continue;
        if(*i > *(i + 1)) std::swap(i, i + 1);
    }
    for(auto i : res)
    {
        if(i == std::end(cont) || i + 1 == std::end(cont)) break;
        if(*i == *(i + 1)) continue;
        if(*i < *(i + 1)) sorted = true; else sorted = false;
    }
    if(sorted) return res; else goto sort;)
}
MAIN_NS_END