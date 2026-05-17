cmake_minimum_required(VERSION 3.15)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "" FORCE)
endif()

project(TextAnalyzer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(modules/data_processor)
add_subdirectory(modules/logger)
add_subdirectory(modules/user_interface)
add_subdirectory(app)
add_subdirectory(tests)