cmake_minimum_required(VERSION 3.4)

project(aurora-trivia LANGUAGES C CXX)

# compile with C++11
set(CMAKE_CXX_STANDARD 11)

# library & binary destinations
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# generate compile_commands.json so editors know header search paths
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add 'aurora' library target
set(ENABLE_TESTS OFF CACHE INTERNAL "disable aurora tests")
set(ENABLE_CPPCHECK OFF CACHE INTERNAL "disable cppcheck")
set(ENABLE_EXAMPLES OFF CACHE INTERNAL "disable examples")
add_subdirectory(lib/aurora)

# trivia game target
add_executable(trivia_game
  trivia.cpp)
target_link_libraries(trivia_game
  aurora)
