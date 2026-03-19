cmake_minimum_required(VERSION 3.19)
project(my_hpx_project CXX)

# Tell CMake where the HPX internal modules are located
# This is the 'cmake' folder inside your HPX source directory
list(APPEND CMAKE_MODULE_PATH "/home/arpit/hpx/src/hpx-1.10.0/cmake")
list(APPEND CMAKE_MODULE_PATH "/home/arpit/hpx/src/hpx-1.10.0/libs/core/command_line_handling_local/cmake")
list(APPEND CMAKE_MODULE_PATH "/home/arpit/hpx/src/hpx-1.10.0/libs/full/parcelport_libfabric/cmake")

# Now find HPX
find_package(HPX REQUIRED)

add_executable(my_hpx_program main.cpp)

# Link the targets
target_link_libraries(my_hpx_program 
    HPX::hpx 
    HPX::wrap_main 
    HPX::iostreams_component
)