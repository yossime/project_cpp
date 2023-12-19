#pragma once
#include <cassert>
#include <cstddef>

template <typename T, typename Predicate, typename UnaryFunc>
// reauires f(T), bool Predicate(T);
void copy_if(T const *begin, T const *end, T *dest, Predicate pred, UnaryFunc f)
{
    if (!begin ||!end ||!dest) {
        return;
    }

    if (end <= begin) {
        return;
    }

    // one more condition to check

    assert( begin < end );
    while(begin != end){
        if (pred(*begin)) {
            *dest = f(*begin);
            ++dest;
        }
        ++begin;
    }
}

inline bool even(int n) { return n % 2 == 0; }
inline bool odd(int n) { return !even(n); }

inline int power2(int n) { return n * n;  }

template<typename T>
T square(T n) { return n * n; }

struct Power{
    size_t exponent;
    int operator()(int n) const {
        int r = 1;
        for (size_t i = 0; i < exponent; i++) {
            r *= n;
        }

        return r;
    }
};

template<typename T>
struct Exponential {
    size_t exponent;
    T operator()(T n) const {
        T r = T{1};
        for (size_t i = 0; i < exponent; i++) {
            r *= n;
        }

        return r;
    }
};

template<typename T>
struct GreaterThan {
    T threshold;
    bool operator()(T n) const {
        return n > threshold;
    }
};
