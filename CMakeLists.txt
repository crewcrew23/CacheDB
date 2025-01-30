cmake_minimum_required(VERSION 2.8)
project(CacheDB)

set(CMAKE_CXX_STANDARD 20)

add_executable(CacheDB src/main.cpp src/parser/CommandParser.cpp 
src/storage/Storage.cpp src/executor/BucketExecutor.cpp  src/executor/DataExecutor.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
