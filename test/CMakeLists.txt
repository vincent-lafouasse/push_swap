cmake_minimum_required(VERSION 3.10)

project(gtest_sandbox)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE) # LSP stuff, don't worry about it

# fetch gtest
# targets: `libgtest` `libgmock` (static libraries)
include(${CMAKE_SOURCE_DIR}/fetch_gtest.cmake)

add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../lib/libft/libft.a"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../lib/libft/include"
)

set(deque_src
  ${CMAKE_SOURCE_DIR}/../src/deque/deque_clear.c
  ${CMAKE_SOURCE_DIR}/../src/deque/deque_new.c
  ${CMAKE_SOURCE_DIR}/../src/deque/deque_peek.c
  ${CMAKE_SOURCE_DIR}/../src/deque/deque_pop.c
  ${CMAKE_SOURCE_DIR}/../src/deque/deque_push.c
  ${CMAKE_SOURCE_DIR}/../src/deque/deque_rotate.c
  ${CMAKE_SOURCE_DIR}/../src/deque/deque_size.c
  ${CMAKE_SOURCE_DIR}/../src/deque/list_new.c
  ${CMAKE_SOURCE_DIR}/../src/deque/t_int_deque.h
)

set(stack_src
  ${CMAKE_SOURCE_DIR}/../src/stack/stack_push.c
  ${CMAKE_SOURCE_DIR}/../src/stack/stack_rotate.c
  ${CMAKE_SOURCE_DIR}/../src/stack/stack_rrotate.c
  ${CMAKE_SOURCE_DIR}/../src/stack/stack_swap.c
  ${CMAKE_SOURCE_DIR}/../src/stack/t_stacks.h
)

set(tested_include_dir
  ${CMAKE_SOURCE_DIR}/../src
)

add_executable(deque
  src/deque/deque_test.cpp
  src/deque/main.cpp

  src/common/custom_assertions.h
  src/common/custom_assertions.cpp

  ${deque_src}
)

target_include_directories(deque PUBLIC
  ${tested_include_dir}
  src
)
target_link_libraries(deque
  libgtest
  libft
)

add_executable(stack
  src/stack/stack_test.cpp
  src/stack/main.cpp

  src/common/custom_assertions.h
  src/common/custom_assertions.cpp

  ${deque_src}
  ${stack_src}

)

target_include_directories(stack PUBLIC
  ${tested_include_dir}
  src
)
target_link_libraries(stack
  libgtest
  libft
)

include(CTest)
enable_testing()

add_test(NAME DequeTest
         COMMAND deque)
add_test(NAME StackTest
         COMMAND stack)
