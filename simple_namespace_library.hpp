/**
* Date: 14.10.2020 19:45
* Copyright by Antoni Kiedos
* Namespace out is based on https://github.com/Fureeish/easy-library.git
* All rights reserved
**/

/*
A simple namespace library
*/

#ifndef GLIBCXX_SIMPLE_NAMESPACE_LIBRARY_HPP_INCLUDED
#define GLIBCXX_SIMPLE_NAMESPACE_LIBRARY_HPP_INCLUDED

#include <iostream>
#include <concepts>
using namespace std;
using namespace std::ranges;
namespace concepts
{
        namespace numberProperties
        {
                auto evn = [ ](auto m) { return m % 2 == 0 };
                auto odd = [ ](auto n) { return n % 2 == 1 };
                auto ngt = [ ] (auto a) {(a/-1) > 0};
                auto pst  = [ ] (auto a) {(a/-1) < 0};
                auto intgr = [ ] (auto a) {round(a) == a};
                auto flt = [ ] (auto a) {round(a) != a};
                auto dv3 = [ ] (auto a) {(a % 3) == 0};
                auto cngr_mod [ ] (auto a, auto b, auto c) {a % c == b % c};
                auto dvdn [ ] (auto a, auto b) {a % b == 0};
        }
}

namespace elementaryArithmetic
{
        auto power = [ ](auto a, auto e)
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
        ostream& operator<<(ostream& wektor, range auto&& zakres) requires (!is_convertible_v<decltype(range), string>)
        {
                auto obecny = begin(zakres);

                if (obecny == end(zakres))
                {
                        return wektor << "||";
                }

                wektor << '|' << *obecny;
                while (++obecny != end(zakres))
                {
                    wektor << ',' << *obecny;
                }

               return wektor << '|';
        }
}
