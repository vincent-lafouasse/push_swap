cmake_minimum_required(VERSION 3.10)

project(gtest_sandbox)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE) # LSP stuff, don't worry about it

# fetch gtest
# targets: `libgtest` `libgmock` (static libraries)
include(${CMAKE_SOURCE_DIR}/fetch_gtest.cmake)

set(libft_dir
  ${CMAKE_SOURCE_DIR}/../lib/libft
)
add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES
  IMPORTED_LOCATION "${libft_dir}/libft.a"
  INTERFACE_INCLUDE_DIRECTORIES "${libft_dir}/include"
)

set(deque_src
  deque_clear.c
  deque_new.c
  deque_peek.c
  deque_pop.c
  deque_push.c
  deque_rotate.c
  deque_size.c
  deque_deep_copy.c
  list_new.c
  t_int_deque.h
)
list(TRANSFORM deque_src PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/../src/deque/)

set(stack_src
  stack_push.c
  stack_rotate.c
  stack_rrotate.c
  stack_swap.c
  t_stacks.h
)
list(TRANSFORM stack_src PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/../src/stack/)

set(tested_include_dir
  ${CMAKE_SOURCE_DIR}/../src
)

set(assertion_module
  src/common/custom_assertions.h
  src/common/custom_assertions.cpp
)

set(common_modules
  ${assertion_module}
)

add_executable(deque
  src/deque/deque_test.cpp
  src/deque/main.cpp

  ${common_modules}
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

  ${common_modules}
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
