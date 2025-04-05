
#pragma once

#include <cstdio>

#ifdef _WIN32
#define fdbg(FMT, ...) do { std::print(stdout, FMT, __VA_ARGS__); std::fputs(stdout, "\n"); std::fflush(stdout); } while (false)
#define ferr(FMT, ...) do { std::print(stderr, FMT, __VA_ARGS__); std::fputs(stdeff, "\n"); std::fflush(stderr); } while (false)
#else
#define fdbg(FMT, ...) do { std::println(stdout, FMT, ##__VA_ARGS__); std::fflush(stdout); } while (false)
#define ferr(FMT, ...) do { std::println(stderr, FMT, ##__VA_ARGS__); std::fflush(stderr); } while (false)
#endif
