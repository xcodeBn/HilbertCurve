cmake_minimum_required(VERSION 3.27)
project(HilbertCurve)

set(CMAKE_CXX_STANDARD 17)

# Path to SFML
set(SFML_DIR "D:/Program Files/SFML-2.6.1/lib/cmake/SFML")

# Find SFML package
find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)

# Set to create a Windows application
set(CMAKE_WIN32_EXECUTABLE TRUE)

# Add the executable
add_executable(HilbertCurve main.cpp HilbertCurve.hpp)

# Link SFML libraries
target_link_libraries(HilbertCurve sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
