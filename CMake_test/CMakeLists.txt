cmake_minimum_required (VERSION 2.8)

project (test)

include_directories (menu student)

aux_source_directory (menu SRC_LIST)
aux_source_directory (student SRC_LIST1)

add_executable (main main.cpp ${SRC_LIST} ${SRC_LIST1})

