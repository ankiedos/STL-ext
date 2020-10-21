# library-plus-plus
Dodatki do różnych standardowych bibliotek. Add-ons for various standard libraries.

# Dokumentacja/Documentation
## simple_namespace_library.hpp:
### przestrzeń nazw concepts/namespace concepts:
#### przestrzeń nazw numberProperties/namespace numberProperties:
- evn()--lambda sprawdzająca czy parzyste/lambda checking if even
- odd()--lambda sprawdzająca czy nieparzyste/lambda checking if odd
- cngr_mod()--lambda sprawdzająca czy ta sama reszta z dielenia/lambda checking if equal remainder
- ngt()--lambda sprawdzająca czy ujemne/lambda checking if negative
- pst()--lambda sprawdzająca czy dodatnie/lambda checking if positive
- intgr()--lambda sprawdzająca czy liczba całkowita UWAGA: Nie dotyczy int tylko czy ma coś po przecinku (np. 1.0 zwróci prawdę)./lambda checking if integer WARNING: It does not apply to the int, but whether it has something after the decimal point (eg 1.0 will return true).
- flt()--lambda sprawdzająca czy liczba zmiennoprzecinkowa UWAGA: Nie dotyczy float tylko czy ma coś po przecinku (np. 1.0 zwróci fałsz)./lambda checking if float number WARNING: It does not apply to the float, but whether it has something after the decimal point (eg 1.0 will return false).
- dv3()--lambda sprawdzająca czy podzielne przez 3/lambda checking if divisible by 3
- dvdn()--lambda sprawdzająca czy podzielne przez coś/lambda checking if divisibile by something

##### planowane/planned:


### przestrzeń nazw elementaryArithmetic/namespace elementaryArithmetic:
- potęga/power


### przestrzeń nazw out/namespace out:
- wektor<<vec;--na podstawie Fureeish/easy-library wyświetlanie std::vector / based on https://github.com/Fureeish/easy-library.git printing the std::vector
