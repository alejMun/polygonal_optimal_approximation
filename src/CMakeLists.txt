cmake_minimum_required(VERSION 3.16)

project(polygonal_optimal_approximation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED COMPONENTS core highgui imgproc imgcodecs)

add_executable(polygonal_optimal_approximation main.cpp utils.cpp)

target_include_directories(polygonal_optimal_approximation
    PRIVATE
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(polygonal_optimal_approximation
    PRIVATE
        ${OpenCV_LIBS}
)
