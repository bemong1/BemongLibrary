cmake_minimum_required(VERSION 2.8)

project(Pimpl_Sample)

add_executable(Pimpl_Sample main.cpp pimpl.cpp)
#add_library(Pimpl SHARED Pimpl.cpp)
#target_link_libraries(Pimpl_Sample Pimpl)

