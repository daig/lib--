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

using uptr = std::uintptr_t;
using iptr = std::intptr_t;
using idiff = std::ptrdiff_t;

using f32 = float;
using f64 = double;

using std::byte;