/**
* Date: 14.10.2020 19:45
* Copyright by Antoni Kiedos
* Based on https://github.com/Fureeish/easy-library
* All rights reserved
**/

/*
A simple namespace library
*/

#ifndef GLIBCXX_SIMPLE_NAMESPACE_LIBRARY_HPP_INCLUDED
#define GLIBCXX_SIMPLE_NAMESPACE_LIBRARY_HPP_INCLUDED
#include "easy.hpp"
#include <iostream>
#include <concepts>
using namespace std;
using namespace std::ranges;
namespace concepts
{
        namespace numberProperties
        {
                auto even = [ ](auto m) { return m % 2 == 0 };
                auto odd = [ ](auto n) { return n % 2 == 1 };
        }
        namespace emenatryArithmetic
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
}
namespace out
{
        ostream& operator<<(ostream& wektor, range auto&& zakres) requires (!is_convertible_v<decltype(range), string>)
        {
                auto obecny = begin(zakres);

                if (obecny == end(zakres))
                {
                return wektor << "{}";
                }

                wektor << '{' << *obecny;
                while (++obecny != end(zakres))
                {
                wektor << ',' << *obecny;
                }

               return wektor << ']';
        }
}