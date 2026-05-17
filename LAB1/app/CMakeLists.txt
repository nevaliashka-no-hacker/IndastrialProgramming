add_executable(text_analyzer main.cpp)

target_include_directories(text_analyzer PRIVATE
    ${CMAKE_SOURCE_DIR}/modules/user_interface/include
    ${CMAKE_SOURCE_DIR}/modules/logger/include
)

target_link_libraries(text_analyzer PRIVATE user_interface)