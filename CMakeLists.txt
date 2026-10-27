cmake_minimum_required(VERSION 3.32)

project(VGB)

add_executable(VGB)

target_sources(VGB
PRIVATE 
    main.cpp
)

add_library(MyLibrary)

target_sources(MyLibrary
  PRIVATE
    main.cpp

  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      CPU
    FILES
      CPU/Definitions.h,
      CPU/Memory.h,
      CPU/Decoder.h
)

target_link_libraries(VGB
    PRIVATE
        MyLibrary
)