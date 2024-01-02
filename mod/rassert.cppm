
module;

#include "alx/trace.h"

export module alx.assert;

import std;

export [[noreturn]] void r_assert(const char* assertion, const char* file, int line)
{
    ferr("Assertion failed: '{}' @{}:{}", assertion, file, line);

    int x = line / (line + 1);
    x = 1/x;
    *static_cast<volatile int*>(nullptr) = x;
    std::terminate();
}

export inline void r_noop() noexcept
{
}
