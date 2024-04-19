cmake_minimum_required(VERSION 3.16)

project(bitmap_sort_cpp
  LANGUAGES CXX
)

set(
  CMAKE_CXX_STANDARD           23
  CMAKE_CXX_STANDARD_REQUIRED  ON
)
set(CMAKE_CXX_FLAGS "-Wall -O3")

find_package(benchmark REQUIRED)


add_executable(bitmap_sort_cpp benchmark.cpp)

target_link_libraries(bitmap_sort_cpp PRIVATE
  benchmark::benchmark
)
