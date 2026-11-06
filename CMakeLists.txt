cmake_minimum_required(VERSION 3.32)

project(VGB)

add_executable(VGB)

target_sources(VGB
PRIVATE 
    main.cpp
)

add_library(MyLibrary
    CPU/CPU.cpp
    CPU/Definitions.cpp
    CPU/Memory.cpp
)

target_sources(MyLibrary
  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      CPU
    FILES
      CPU/Definitions.h
      CPU/Memory.h
      CPU/CPU.h
)

target_link_libraries(VGB
    PRIVATE
        MyLibrary
)