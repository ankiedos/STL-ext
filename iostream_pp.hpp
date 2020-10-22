#include "simple_nmespace_library.hpp"
#include <concepts>
using namespace std;
using namespace std::ranges;
using namespace out;

namespace out
{
  ostream& operator<<(ostream& zbior, range auto&& zbior_r) requires (!is_convertible_v<decltype(range), string>)
  {
     auto teraz = begin(zbior_r);

                if (teraz == end(zbior_r))
                {
                        return zbior << "{}";
                }

                zbior << '{' << *teraz;
                while (++teraz != end(zbior_r))
                {
                    zbior << ',' << *teraz;
                }

               return zbior << '}';
}
