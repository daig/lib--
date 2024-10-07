#pragma once
#include <cstdint>
#include <cstddef>
#include <cstdio>

using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;
using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using i8 = int8_t;

//a count of bytes returned by sizeof
using usize = std::size_t;
static_assert(sizeof(usize) == sizeof(u64), "usize is not 64 bits");

// using isize = std::ssize_t;
// static_assert(sizeof(isize) == sizeof(i64), "isize is not 64 bits");

using uptr = std::uintptr_t;
static_assert(sizeof(uptr) == sizeof(u64), "uptr is not 64 bits");
using iptr = std::intptr_t;
static_assert(sizeof(iptr) == sizeof(i64), "iptr is not 64 bits");
// using idiff = std::ptrdiff_t;

using f32 = float;
using f64 = double;

using b8 = std::byte;
using b1 = bool;

using c8 = char8_t;
using c16 = char16_t;
using c32 = char32_t;

//(wchar_t is an abomination)