cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Project name and supported languages
project(libmm LANGUAGES CXX)

add_library(libmm INTERFACE)
target_include_directories(libmm INTERFACE src)
