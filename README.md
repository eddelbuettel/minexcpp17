## Minimal C++17 Example:  Breaks using `g++-11`, Passes using `g++-10`

The C++17 standard introduced `std::data()` which turns the code here, a
reduced version of what is in [RcppSMC](https://github.com/rcppsmc/rcppsmc)
into something that compiles under C++11 or C++14 -- but not C++17.

It has not yet been worked here which package, if any, is at fault. 

Quick solutions are to add `CXX_STD=CXX14`, say, to `src/Makevars`, or to not
use `using namespace std;` so that `std::data` does not clash with `LinRegNS::data`.

