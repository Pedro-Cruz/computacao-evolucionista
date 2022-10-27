# The name of our project.
project(sample_project)
cmake_minimum_required(VERSION 3.16)
# Look for an installation of pagmo in the system.
find_package(Pagmo REQUIRED)

# Create an executable, and link it to the Pagmo::pagmo imported target.
# This ensures that, in the compilation of 'getting_started', pagmo's include
# dirs are added to the include path of the compiler and that pagmo's
# dependencies are transitively linked to 'getting_started'.
add_executable(getting_started getting_started.cpp)
target_link_libraries(getting_started Pagmo::pagmo)
