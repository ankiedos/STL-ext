/**
* Date: 22.10.2020 15:34
* Copyright by Antoni Kiedos
* License: GNU GPLv3 or higher
**/

/*
An extension to the iostream library: "iostream++"
Include directive name: "iostream_pp.hpp"
*/

#include "temp_lib.hpp"
#include<concepts>
#include<ranges>
#include<iostream>

namespace out
{
    std::ostream& operator<<(std::ostream& set, std::ranges::range auto&& range)
    {
        if constexpr(!std::is_convertible_v<decltype(range), std::string>)
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
        else return set << std::to_string(range);
    }
}
