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
    concept is_sorted_container = requires(T cont)
    {
        std::sort(cont.begin(), cont.end()) == cont;
        cont.begin();
        cont.end();
        cont.size();
        cont.empty();
        cont.emplace() || cont.push();
    };
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
namespace Algorithms
{
    auto fast_power(auto a, auto e)
    {
        auto res = 1.0;
        while(e > 0)
        {
            if(e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    std::optional<decltype(x)> BinarySearch(auto min, auto x, auto max) // "auto" is not allowed in this place
    {
        assert(min < max);
        auto middle = min + max / 2;
        if(x > middle) BinarySearch(middle, max);
        else if(x < middle) BinarySearch(min, middle);
        else if(x == middle) return x;
        else return {};
    }
    std::optional<decltype(x)> SortAndBinarySearch(auto min, auto x, auto max)
    {
        std::sort(min, max);
        return BinarySearch(min, x, max);
    }
    namespace Ranges
    {
        template<typename Searched, Concepts::is_sorted Container = std::vector<Searched>>
        std::optional<decltype(x)> BinarySearch(Container container, Searched x)
        {
            auto middle = container.begin() + container.end() / 2;
            if(x > middle) BinarySearch(middle, container.end());
            else if(x < middle) BinarySearch(container.begin(), middle);
            else if(x == middle) return x;
            else return {};
        }
        std::optional<decltype(x)> SortAndBinarySearch(auto container, auto x)
        {
            std::ranges::sort(container);
            return BinarySearch(container, x);
        }
    }
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