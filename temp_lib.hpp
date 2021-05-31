/**
* Date: 14.10.2020 19:45
* Copyright by Antoni Kiedos
* Namespace out is based on https://github.com/Fureeish/easy-library.git
* License: GNU GPLv3 or higher
**/

/*
A temporary library which will be divided into separate files
*/

#include<iostream>
#include<concepts>
#include<vector>
#include<cmath>
#include<ranges>
#include<optional>
#include<algorithm>
#include<cassert>
#include<defs.hpp>

MAIN_NS_BEGIN
namespace Concepts
{
    template<typename T>
    concept CopyConstructible = requires()
    {
        T(typename const T&)
    };
    template<typename T>
    concept IterableContainer = requires(T cont)
    {
        cont.begin() || cont.Begin();
        cont.end() || cont.End();
        T::iterator || T::Iterator;
    };
    template<typename T>
    concept ReversibleIterableContainer = requires(T cont)
    {
        IterableContainer<T>;
        cont.rbegin() || cont.Rbegin() || cont.RBegin();
        cont.rend() || cont.Rend() || cont.REnd();
        T::reverse_iterator || T::ReverseIterator;
    };
    template<typename T>
    concept ConstantIterableContainer = requires(T cont)
    {
        cont.cbegin() || cont.Cbegin() || cont.CBegin();
        cont.cend() || cont.Cend() || cont.CEnd();
        T::const_iterator || T::ConstIterator;
    };
    template<typename T>
    concept ConstantReversibleIterableContainer = requires(T cont)
    {
        cont.crbegin() || cont.Crbegin() || cont.CRbegin() || cont.CRBegin();
        cont.crend() || cont.Crend() || cont.CRend() || cont.CREnd();
        T::const_reverse_iterator || T::ConstReverseIterator;
    };
    template<typename T>
    concept RandomAccessContainer = requires()
    {
        T::operator [];
    };
    template<typename T>
    concept SortedContainer = requires(T cont)
    {
        std::sort(cont.begin(), cont.end()) == cont;
        cont.begin();
        cont.end();
        cont.size();
        cont.empty();
        cont.emplace() || cont.push();
    };
    [[deprecated("concept template is_sorted_container<T> is deprecated. Please use SortedContainer instead!\n")]]
    template<typename T>
    concept is_sorted_container = SortedContainer;
    [[deprecated("concept template is_sorted<T> is deprecated. Please use SortedContainer instead!\n")]]
    template<typename T> // For backward compatibility
    concept is_sorted = requires(T cont)
    {
        std::sort(cont.begin(), cont.end()) == cont;
    };
}
namespace Filters
{
    namespace numberProperties
    {
        auto evn = [](auto m)                       { return m % 2 == 0 };
        auto odd = [](auto n)                       { return n % 2 == 1 };
        auto ngt = [](auto a)                       { return (a / -1) > 0 };
        auto pst  = [](auto a)                      { return (a / -1) < 0 };
        auto intgr = [](auto a)                     { return std::round(a) == a };
        auto flt = [](auto a)                       { return std::round(a) != a };
        auto dv3 = [](auto a)                       { return (a % 3) == 0 };
        auto cngr_mod = [](auto a, auto b, auto c)  { return (a % c) == (b % c) };
        auto dvdn = [](auto a, auto b)              { return a % b == 0 };
    }
}

namespace elementaryArithmetic
{
    auto power = [](auto a, auto e)
    {
        for(int i = 0; i <= e / 2; i++)
        {
            a *= a;
        }
        return a;
    };
}
namespace Out
{
    std::ostream& operator<<(std::ostream& vector, std::ranges::range auto&& range) requires (!is_convertible_v<decltype(range), std::string>)
    {
        auto current = std::begin(range);

        if(current == std::end(range))
        {
            return vector << "||";
        }

        vector << '|' << *current;
        while(++current != std::end(range))
        {
            vector << ',' << *current;
        }

        return vector << '|';
    }
}
MAIN_NS_END