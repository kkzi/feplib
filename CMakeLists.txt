project(feptest)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/feplib/include)
link_directories(${CMAKE_SOURCE_DIR}/feplib/lib/x64-Debug)

add_executable(fep_recv fep_recv.cpp)
add_executable(fep_send fep_send.cpp)

target_link_libraries(fep_recv PRIVATE feplib)
target_link_libraries(fep_send PRIVATE feplib)



