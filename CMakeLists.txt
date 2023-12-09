cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)

include_directories(C:\\dev\\vcpkg\\installed\\x86-windows\\include)
link_directories(C:\\dev\\vcpkg\\installed\\x86-windows\\lib)

add_executable(Main 00/ip_maths.c)

target_link_libraries(Main)