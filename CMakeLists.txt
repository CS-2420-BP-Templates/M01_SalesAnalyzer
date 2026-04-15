cmake_minimum_required(VERSION 3.27)
project(01_SalesAnalyzer)

set(CMAKE_CXX_STANDARD 17)

# IMPORTANT: Enable CTest support
enable_testing()

# Create the library
set(LIB_NAME mylib)

add_library(mylib
        SalesAnalyzer.cpp   # Only the .cpp file
)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Main program
add_executable(01_SalesAnalyzer SalesAnalyzer.h
        main.cpp
)

target_link_libraries(01_SalesAnalyzer
        PUBLIC ${LIB_NAME}
)
add_subdirectory(tests)

