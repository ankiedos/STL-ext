/**
* Date: 14.10.2020 19:45
* Copyright by Antoni Kiedos
* Namespace out is based on https://github.com/Fureeish/easy-library.git
**/

/*
A simple namespace library
*/

#include <iostream>
#include <concepts>
#include <cmath>
namespace concepts
{
    namespace numberProperties
    {
        auto evn = [](auto m) { return m % 2 == 0 };
        auto odd = [](auto n) { return n % 2 == 1 };
        auto ngt = [] (auto a) {(a/-1) > 0};
        auto pst  = [] (auto a) {(a/-1) < 0};
        auto intgr = [] (auto a) {std::round(a) == a};
        auto flt = [] (auto a) {std::round(a) != a};
        auto dv3 = [] (auto a) {(a % 3) == 0};
        auto cngr_mod = [] (auto a, auto b, auto c) {a % c == b % c};
        auto dvdn = [] (auto a, auto b) {a % b == 0};
    }
}

namespace elementaryArithmetic
{
    auto power = [](auto a, auto e)
    {
        for(int i=0; i <= e/2; i++)
        {
            a*=a;
        }
        return a;
    }
}

namespace out
{
    ostream& operator<<(ostream& wektor, std::ranges::range auto&& zakres) requires (!is_convertible_v<decltype(zakres), string>)
    {
        auto obecny = std::begin(zakres);

        if(obecny == std::end(zakres))
        {
            return wektor << "||";
        }

        wektor << '|' << *obecny;
        while(++obecny != std::end(zakres))
        {
            wektor << ',' << *obecny;
        }

        return wektor << '|';
    }
}
