cmake_minimum_required(VERSION 3.10)
project(imgCmp)

# Add executable from src directory
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} IL ILU ILUT)


target_compile_options(imgCmp PRIVATE 
    -Wall -Wextra -Wpedantic -Werror
)