/**
* Date: 14.10.2020 19:45
* Copyright by Antoni Kiedos
* Namespace out is based on https://github.com/Fureeish/easy-library.git
**/

/*
A simple namespace library
*/

#include<iostream>
#include<concepts>
#include<cmath>
#include<ranges>

namespace concepts
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
    }
}

namespace out
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