# Our C++ project contains a single executable built from main.cpp
# It uses the definitions in my_library.cpp,  which are defined in the header file my_library.h

# Lets compile the library first
add_library(main_library  homework_17.cpp)
target_include_directories(main_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Now we compile the executable
# We need to tell CMake that we want to build an executable
add_executable(my_executable main.cpp)
set_target_properties(my_executable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/homework)

# We need to tell CMake that the executable depends on the library
# This is done by linking the library to the executable
target_link_libraries(my_executable main_library)