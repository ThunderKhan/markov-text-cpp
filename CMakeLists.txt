cmake_minimum_required(VERSION 3.16)

project(markov_text
    VERSION 0.1
    LANGUAGES CXX
)

# -------------------------------------------------
# C++ standard
# -------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------------------------
# Library: core Markov engine
# -------------------------------------------------
add_library(markov_text
    src/generator.cpp
    src/model.cpp
    src/tokenizer.cpp
    src/trainer.cpp
    src/types.cpp
)

target_include_directories(markov_text
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

if (MSVC)
    target_compile_options(markov_text PRIVATE /W4)
else()
    target_compile_options(markov_text PRIVATE -Wall -Wextra -Wpedantic)
endif()

# -------------------------------------------------
# Executable: CLI / main program
# -------------------------------------------------
add_executable(markov_text_cli
    src/main.cpp
)

target_link_libraries(markov_text_cli
    PRIVATE
        markov_text
)
