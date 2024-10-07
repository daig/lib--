#pragma once
#include "types.h"

template <class T, size_t N>
struct array {
  // types:
  T elems[N];

  // No explicit construct/copy/destroy for aggregate type
  constexpr void fill(T const& u) { std::fill_n(data(), N, u); }

  constexpr void swap(array& a) noexcept(NoThrowSwappable<T>) {
    std::swap_ranges(data(), data() + N, a.data()); }

  // iterators:
  constexpr T      * begin()       noexcept { return data(); }
  constexpr T const* begin() const noexcept { return T const*(data()); }
  constexpr T      * end()         noexcept { return data() + N; }
  constexpr T const* end()   const noexcept { return T const*(data() + N); }

  constexpr std::reverse_iterator<T      *> rbegin()       noexcept { return std::reverse_iterator<T      *>(end()); }
  constexpr std::reverse_iterator<T const*> rbegin() const noexcept { return std::reverse_iterator<T const*>(end()); }
  constexpr std::reverse_iterator<T      *> rend()         noexcept { return std::reverse_iterator<T      *>(begin()); }
  constexpr std::reverse_iterator<T const*> rend()   const noexcept { return std::reverse_iterator<T const*>(begin()); }

  constexpr T const* cbegin() const noexcept { return begin(); }
  constexpr T const* cend()   const noexcept { return end(); }
  constexpr std::reverse_iterator<T const*> crbegin() const noexcept { return rbegin(); }
  constexpr std::reverse_iterator<T const*> crend() const noexcept { return rend(); }

  // capacity:
  constexpr size_t size()     const noexcept { return N; }
  [[__nodiscard__]] constexpr bool empty() const noexcept { return N == 0; }

  // element access:
  constexpr T& operator[](size_t n) noexcept {
    assert(n < N && "out-of-bounds access in std::array<T, N>");
    return elems[n];
  }
  constexpr T const& operator[](size_t n) const noexcept {
    assert(n < N && "out-of-bounds access in std::array<T, N>");
    return elems[n];
  }

  constexpr T& at(size_t n) {
    if (n >= N) {__throw_out_of_range("array::at");}
    return elems[n]; }

  constexpr T const& at(size_t n) const {
    if (n >= N) {__throw_out_of_range("array::at");}
    return elems[n]; }

  constexpr T      & front()       noexcept { return (*this)[0]; }
  constexpr T const& front() const noexcept { return (*this)[0]; }
  constexpr T      & back()        noexcept { return (*this)[N - 1]; }
  constexpr T const& back() const  noexcept { return (*this)[N - 1]; }

  constexpr T      * data()       noexcept { return elems; }
  constexpr T const* data() const noexcept { return elems; }
};


template <class T> concept NonVoid = !std::is_void<T>::value;

template <class T, class U = T>
concept Swappable = NonVoid<T> && NonVoid<U> && requires(T&& t, U&& u) {
    { swap(std::forward<T>(t), std::forward<U>(u)) } -> std::same_as<void>;
};

template <class T, class U = T>
concept NoThrowSwappable = NonVoid<T> && NonVoid<U> && requires(T&& t, U&& u) {
    { swap(std::forward<T>(t), std::forward<U>(u)) } noexcept -> std::same_as<void>;
};

template <std::input_iterator A, std::input_iterator B>
struct iter_pair {
    using reference_t = std::pair<typename A::T&, typename B::T&>;

    reference_t  operator*() { return {*a, *b}; }
    iter_pair& operator++() { ++a; ++b; return *this; }
    iter_pair  operator++(int) { iter_pair tmp = *this; ++*this; return tmp; }
    bool       operator==(const iter_pair& other) const { return a == other.a || b == other.b; }
    bool       operator!=(const iter_pair& other) const { return a != other.a && b != other.b; }

    A a; B b;
};

template <typename A, typename B>
struct zip {
    A a; B b;

    zip(A a, B b) : a(a), b(b) {}

    using iterator = iter_pair<typename A::iterator, typename B::iterator>;
    iterator begin() const noexcept { return iter_pair{a.begin(), b.begin()}; }
    iterator end() const noexcept { return iter_pair{a.end(), b.end()}; }
};
