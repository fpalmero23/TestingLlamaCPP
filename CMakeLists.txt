# COMPILE CONFIGURATION
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER gcc)
# if (MSVC)
#     add_compile_options(/W3)
# else()
#     add_compile_options(-Wall -Wextra)
# endif()

# PROJECT
set(PROJECT_NAME TestingLlama)
project(${PROJECT_NAME})

# Incluir llama.cpp como subdirectorio
add_subdirectory(llama.cpp)

# Agregar el ejecutable
add_executable(${PROJECT_NAME} main.cpp)

# Incluir directorios necesarios
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/llama.cpp
    ${CMAKE_SOURCE_DIR}/llama.cpp/ggml/include
    ${CMAKE_SOURCE_DIR}/llama.cpp/common
)

# Enlazar contra la librería llama
target_link_libraries(${PROJECT_NAME} PRIVATE llama)
