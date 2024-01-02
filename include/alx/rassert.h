
#pragma once

#define R_ASSERT(cond) (((cond)) ? r_noop() : r_assert(#cond, __FILE__, __LINE__))
#define UNREACHABLE r_assert("Unreachable", __FILE__, __LINE__)
