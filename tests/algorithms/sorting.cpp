#include<gtest/gtest.h>
#include<includes/algorithms/sorting.hpp>
#include<vector>
#include<array>

TEST(BubbleSort_ByVal_Test, sorted_container)
{
    std::vector<int> vec = {0, 1, 2, 3, 4};
    auto res = stdext::Algorithms::BubbleSort(vec);
    ASSERT_EQ(res, vec);
}
TEST(BubbleSort_ByVal_Test, first_element_non_sorted_greater_than_remainder)
{
    std::array<int, 6> arr = {9, 0, 1, 2, 3, 4};
    auto res = stdext::Algorithms::BubbleSort(arr);
    ASSERT_EQ(res, {0, 1, 2, 3, 4, 9});
}
TEST(BubbleSort_ByVal_Test, last_element_non_sorted_lesser_than_remainder)
{
    std::array<short, 7> arr = {0, 1, 2, 3, 4, 5, -1};
    auto res = stdext::Algorithms::BubbleSort(arr);
    ASSERT_EQ(res, {-1, 0, 1, 2, 3, 4, 5});
}
TEST(BubbleSort_ByVal_Test, some_nonrepeting_unordered_numbers)
{
    std::array<unsigned short, 10> arr = {2, 4, 12, 5, 3, 45, 7, 9, 2354, 447};
    auto res = stdext::Algorithms::BubbleSort(arr);
    ASSERT_EQ(res, {2, 3, 4, 5, 7, 9, 12, 45, 447, 2354});
}
TEST(BubbleSort_ByVal_Test, some_repeting_unordered_numbers)
{
    std::array<int, 6> arr = {4, 5, 6, 3, 4, 896};
    auto res = stdext::Algorithms::BubbleSort(arr);
    ASSERT_EQ(res, {3, 4, 4, 5, 6, 896});
}