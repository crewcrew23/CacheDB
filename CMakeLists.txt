cmake_minimum_required(VERSION 3.30)
project(CacheDB)

set(CMAKE_CXX_STANDARD 20)

add_executable(CacheDB src/main.cpp src/parser/CommandParser.cpp src/storage/Storage.cpp src/executor/BucketExecutor.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
