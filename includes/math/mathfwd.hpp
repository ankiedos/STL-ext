MAIN_NS_BEGIN
namespace Math
{
    template<intmax_t Num, intmax_t Denom>
    using Equation = basic_Equation<std::ratio<Num, Denom>>;
}