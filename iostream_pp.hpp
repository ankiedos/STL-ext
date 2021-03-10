/**
* Date: 22.10.2020 15:34
* Copyright by Antoni Kiedos
**/

/*
An extension to the iostream library: "iostream++"
Include directive name: "iostream_pp.hpp"
*/

#include "temp_lib.hpp"
#ifdef __VSCODE__
#define __cpp_lib_concepts
#endif
#include<concepts>
#include<ranges>
#include<iostream>
#ifdef __VSCODE__
#pragma warning(disable : 135 3249)
#endif
namespace out
{
    std::ostream& operator<<(std::ostream& set, std::ranges::range auto&& range) requires (!std::is_convertible_v<decltype(range), std::string>)
    {
        auto current = std::begin(range);

        if(current == std::end(range))
        {
            return set << "{}";
        }

        set << '{' << *current;
        while(++current != std::end(range))
        {
            set << ',' << *current;
        }

        return set << '}';
    }
}
