# library-plus-plus
Dodatki do standardowej biblioteki C++. Add-ons for C++ standard library.

# Dokumentacja/Documentation
## temp_lib.hpp:
### przestrzeń nazw Concepts __/__ namespace Concepts:
- is_sorted<Container> -- sprawdza czy posortowany __/__ checks if container is sorted

### przestrzeń nazw Filters __/__ namespace Filters:
#### przestrzeń nazw numberProperties/namespace numberProperties:
- evn--lambda sprawdzająca czy parzyste __/__ lambda checking if even
- odd--lambda sprawdzająca czy nieparzyste __/__ lambda checking if odd
- cngr_mod--lambda sprawdzająca czy ta sama reszta z dielenia __/__ lambda checking if equal remainder
- ngt--lambda sprawdzająca czy ujemne __/__ lambda checking if negative
- pst--lambda sprawdzająca czy dodatnie __/__ lambda checking if positive
- intgr--lambda sprawdzająca czy liczba całkowita **UWAGA: Nie dotyczy int tylko czy ma coś po przecinku (np. 1.0 zwróci prawdę).** __/__ lambda checking if integer **WARNING: It does not apply to the int, but whether it has something after the decimal point (eg 1.0 will return true).**
- flt--lambda sprawdzająca czy liczba zmiennoprzecinkowa **UWAGA: Nie dotyczy float tylko czy ma coś po przecinku (np. 1.0 zwróci fałsz).** __/__ lambda checking if float number **WARNING: It does not apply to the float, but whether it has something after the decimal point (eg 1.0 will return false).**
- dv3--lambda sprawdzająca czy podzielne przez 3 __/__ lambda checking if divisible by 3
- dvdn--lambda sprawdzająca czy podzielne przez coś __/__ lambda checking if divisibile by something

### przestrzeń nazw elementaryArithmetic __/__ namespace elementaryArithmetic:
- power -- filtr potęgujący __/__ powering filter
- fast_power-- filtr wykorzystujący algorytm szybkiego potęgowania __/__ filter using fast powering algorithm

### przestrzeń nazw Algorithms __/__ namespace Algorithms:
- BinarySearch(min, x, max) -- wymaga, aby kontener był posortowany, jeśli min == cont.begin() && max == cont.end() __/__ requires container is sorted, if min == cont.begin() && max == cont.end()
- SortAndBinarySearch(min, x, max)
#### przestrzeń nazw Ranges __/__ namespace Ranges:
uzakresowione algorytmy z przestrzeni nazw Algorithm __/__ ranged algorithms from Algorithim namespace
- BinarySearch<Searched, Container = std::vector<Searched>(container, x) -- wymaga spełnienia Concepts:is_sorted<Container<Searched.. __/__ requires satisfied Concepts:is_sorted<Container<Searched>>
- SortAndBinarySearch(container, x)
### przestrzeń nazw Out __/__ namespace Out:
- vector << vec;--na podstawie https://github.com/Fureeish/easy-library.git wyświetlanie std::vector __/__ based on https://github.com/Fureeish/easy-library.git printing the std::vector
--------
### planowane __/__ planned:
