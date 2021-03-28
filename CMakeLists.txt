# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

if(POLICY CMP0042)
  cmake_policy(SET CMP0042 NEW)  # CMake 3.0+ (2.8.12): MacOS "@rpath" in target's install name
endif()

# 项目工程名
project(Chordmata LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "root This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "root This is SOURCE dir " ${PROJECT_SOURCE_DIR})

# 添加子目录
ADD_SUBDIRECTORY(src)
