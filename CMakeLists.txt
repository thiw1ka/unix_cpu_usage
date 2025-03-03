cmake_minimum_required(VERSION 3.10)
project(cpu_usage_logger)
set(CXX_STANDARD 17)
link_libraries(-lstdc++fs)

# Find includes
include_directories(include)

# Define source files
file(GLOB SOURCES "src/main.cpp")

# Add executable
add_executable(cpu_usage_logger ${SOURCES})

# Link libraries (if needed)
# target_link_libraries(my_executable library1 library2)