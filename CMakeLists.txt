cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(muxtest C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(muxtest
  muxtest.c
)

target_include_directories(muxtest PRIVATE ${CMAKE_CURRENT_LIST_DIR})

pico_add_extra_outputs(muxtest)
target_link_libraries(muxtest PRIVATE pico_stdlib)
