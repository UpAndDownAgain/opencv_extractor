cmake_minimum_required(VERSION 3.15)
project(opencv_extractor)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

add_executable(opencv_extractor main.cpp)
target_link_libraries(opencv_extractor ${OpenCV_LIBS} )
