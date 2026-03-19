cmake_minimum_required(VERSION 3.19)
project(HPXMatrixMultiplication CXX)

# Tell CMake where the HPX internal modules are located
list(APPEND CMAKE_MODULE_PATH "/home/arpit/hpx/src/hpx-1.10.0/cmake")
list(APPEND CMAKE_MODULE_PATH "/home/arpit/hpx/src/hpx-1.10.0/libs/core/command_line_handling_local/cmake")
list(APPEND CMAKE_MODULE_PATH "/home/arpit/hpx/src/hpx-1.10.0/libs/full/parcelport_libfabric/cmake")

# Find the HPX package settings
find_package(HPX REQUIRED)

# Define the matrix_ops component library
add_hpx_component(matrix_ops
    SOURCES components/matrix_ops.cpp
    HEADERS components/matrix_ops.hpp
)

# Define the client executable and link it to matrix_ops and iostreams
add_hpx_executable(matmul_client
    SOURCES client/main.cpp
    COMPONENT_DEPENDENCIES matrix_ops
)

# Link additional components
target_link_libraries(matmul_client
    PRIVATE HPX::iostreams_component
)
