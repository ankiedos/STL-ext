#pragma once
#include<optional>
#include<../../temp_lib.hpp>

MAIN_NS_BEGIN
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
        template<typename Searched, typename Container = std::vector<Searched>>
        requires Concepts::SortedContainer<Container>
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
MAIN_NS_END