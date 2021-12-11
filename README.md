## Minimal C++17 Example:  Breaks using `g++-11`, Passes using `g++-10`

The C++17 standard introduced `std::data()` which turns the code here, a
reduced version of what is in [RcppSMC](https://github.com/rcppsmc/rcppsmc)
into something that compiles under C++11 or C++14 -- but not C++17.

Quick solutions are to add `CXX_STD=CXX14`, say, to `src/Makevars`, or to not
use `using namespace std;` so that `std::data` does not clash with `LinRegNS::data`.

### Self-contained Example

The issue isolated in the small package here can also be seen in the (even
smaller) file below:

```c++

#include <iterator>

namespace foo {
    class bar {
    public:
        double a;
    };

    bar data;
}

using namespace std;
using namespace foo;

int main(void) {
    data.a = 1.1;
    exit(0);
}
```

It compiles fine under `g++-10`, but not under `g++-11` which, by defaulting
to C++17, brings us `std::data()` which clashes with the simple `foo::data`
here _because both namespaces are flattened_.  Fixes are any one of 

- not flattening the namespaces but prefixing properly (that's what
  namespaces are for anyway ...)
- compiling under a C++ standard older than C++17, _e.g._ `g++-11 -std=c++14`
- renaming `foo::data`

### Author

Dirk Eddelbuettel

### License

GPL (>= 2)
