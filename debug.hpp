#ifndef DEBUG_HPP
#define DEBUG_HPP
#include <iostream>
#include <chrono>
#include <cstdio>

using namespace std;

#ifndef ONLINE_JUDGE

/* ---------- START / END (local only) ---------- */

#define __START__                                           \
    auto __begin = chrono::high_resolution_clock::now();   \
    freopen("inputf.in", "r", stdin);                      \
    freopen("outputf.in", "w", stdout);                    \
    freopen("error.txt", "w", stderr);

#define __END__                                             \
    auto __end = chrono::high_resolution_clock::now();     \
    cerr << "Execution time: "                              \
         << chrono::duration<double>(__end - __begin).count() \
         << " s\n";

/* ---------- DEBUG PRINT ---------- */

template <typename T>
void __print(const T &x) { cerr << x; }

template <typename T, typename... V>
void __print(const T &t, const V &...v)
{
    cerr << t;
    if (sizeof...(v))
        cerr << ", ";
    __print(v...);
}

#define debug(...)                                          \
    cerr << "[Line " << __LINE__ << "] "                    \
         << #__VA_ARGS__ << " = ",                          \
         __print(__VA_ARGS__), cerr << "\n";

#else

#define __START__
#define __END__
#define debug(...)

#endif

#endif
