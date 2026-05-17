add_library(user_interface STATIC src/ui.cpp)

# Путь к собственным заголовкам
target_include_directories(user_interface PUBLIC include)

# Пути к заголовкам зависимых модулей
target_include_directories(user_interface PRIVATE 
    ${data_processor_SOURCE_DIR}/include
    ${logger_SOURCE_DIR}/include
)

target_link_libraries(user_interface PRIVATE data_processor logger)