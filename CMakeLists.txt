cmake_minimum_required(VERSION 3.15)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
aux_source_directory(src SRC_FILES)
aux_source_directory(. CWD_FILES)

add_library(tic_tac_toe SHARED ${SRC_FILES})
add_executable(tic_tac_toe ${CWD_FILES} ${SEC_FILES})

add_subdirectory(test)