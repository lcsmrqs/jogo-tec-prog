cmake_minimum_required(VERSION 3.22)

project(resgate_emilia)

find_package(SFML COMPONENTS graphics)

add_subdirectory(src)

target_link_libraries(resgate_emilia sfml-graphics)
