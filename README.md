# library-plus-plus
Add-ons for C++ standard library.
This repository has the following submodules:
- [neargye/nameof](https://github.com/neargye/nameof), license: MIT
# Troubleshooting builds (on Windows)
If you have an error message after `mingw32-make` (I don't know if with `make` also isn't working) like the following:
```
Command failed: Cannot find the file specified

   'C:/Program'

  See also

    C:/Users/antek/Documents/GitHub/library-plus-plus/build/googletest-prefix/src/googletest-stamp/googletest-build-*.log


mingw32-make[2]: *** [CMakeFiles\googletest.dir\build.make:88: googletest-prefix/src/googletest-stamp/googletest-build] Error 1
mingw32-make[1]: *** [CMakeFiles\Makefile2:112: CMakeFiles/googletest.dir/all] Error 2
mingw32-make: *** [Makefile:90: all] Error 2
```
then do:
- go to the googletest.dir/build.make
- after that, prepend line 88 with `setlocal EnableExtensions && `,
- go to lib++_ut.dir/build.make,
- make rules with the same result at lines 125-130 to be at most 2 rules
- in those rules, remove semicolons (`;`) from prerequisites matching the regex `/lib\/lib;g((mock)|(test))(_main)?/`

# Documentation
## temp_lib.hpp:
### namespace Concepts:
- is_sorted<Container> -- checks if container is sorted

### namespace Filters:
#### namespace numberProperties:
- evn--lambda checking if even
- odd--lambda checking if odd
- cngr_mod--lambda checking if equal remainder
- ngt--lambda checking if negative
- pst--lambda checking if positive
- intgr--lambda checking if integer **WARNING: It does not apply to the int, but whether it has something after the decimal point (e.g. with 1.0 will return true).**
- flt--lambda checking if float number **WARNING: It does not apply to the float, but whether it has something after the decimal point (e.g. with 1.0 will return false).**
- dv3--lambda checking if divisible by 3
- dvdn--lambda checking if divisible by something

### namespace Arithmetic:
- power -- filter returning a (second arg)th power of its first arg
- fast_power -- filter using fast powering algorithm

### namespace Algorithms:
- `BinarySearch(min, x, max)` -- requires container being sorted, if `min == some_cont.begin() && max == some_cont.end()`
- `SortAndBinarySearch(min, x, max)`
#### namespace Ranges:
ranged algorithms from Algorithm namespace
- `BinarySearch<Searched, Container = std::vector<Searched>(container, x)` -- requires `Concepts:is_sorted<Container<Searched>>` being satisfied
- `SortAndBinarySearch(container, x)`
### namespace Out:
- `std::cout << vec;` -- based on https://github.com/Fureeish/easy-library.git; printing the std::vector
--------
### planned:


# License
Whole library is licensed under the [GNU GPLv3](https://github.com/ankiedos/library-plus-plus/blob/main/.github/LICENSE.md) (or higher) license.