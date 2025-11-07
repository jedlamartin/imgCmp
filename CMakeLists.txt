cmake_minimum_required(VERSION 3.10)
project(imgCmp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find DevIL packages
find_package(DevIL REQUIRED)

# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Include directories
if(IL_INCLUDE_DIR)
    target_include_directories(${PROJECT_NAME} PRIVATE ${IL_INCLUDE_DIR})
endif()

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    ${IL_LIBRARIES}    # Main DevIL library
    ${ILU_LIBRARIES}   # DevIL Utility library
    ${ILUT_LIBRARIES}  # DevIL Tool Utility library
)

# If the above variables are not properly set by FindDevIL, we'll link directly
if(NOT IL_FOUND)
    target_link_libraries(${PROJECT_NAME} 
        IL
        ILU
        ILUT
    )
endif()

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)