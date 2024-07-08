cmake_minimum_required(VERSION 3.10)

project(gtest_sandbox)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE) # LSP stuff, don't worry about it

# fetch gtest
# targets: `libgtest` `libgmock` (static libraries)
include(${CMAKE_SOURCE_DIR}/fetch_gtest.cmake)

add_executable(deque_test
  src/test.cpp
  src/main.cpp

  ${CMAKE_SOURCE_DIR}/../src/stack/t_int_deque.h
  ${CMAKE_SOURCE_DIR}/../src/stack/deque_new.c
)

target_include_directories(deque_test PUBLIC
  ${CMAKE_SOURCE_DIR}/../src/stack
)
target_link_libraries(deque_test
  libgtest
)

