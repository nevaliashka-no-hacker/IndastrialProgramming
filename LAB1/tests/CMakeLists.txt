# Подключение Google Test через FetchContent (CMake 3.11+)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests test_processor.cpp)
target_link_libraries(run_tests PRIVATE data_processor gtest_main)
target_include_directories(run_tests PRIVATE ${data_processor_SOURCE_DIR}/include)