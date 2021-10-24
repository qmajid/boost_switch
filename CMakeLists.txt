# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (switch)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/Hello.cpp
    src/thread_pool.cpp
    src/parser.cpp
    src/output_queue.cpp
)

# --------- LIBS --------------------
# find a boost install with the libraries filesystem and system
find_package(Boost 1.46.1 REQUIRED COMPONENTS system thread) 

# check if boost was found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()
# --------- LIBS --------------------


# Add an executable
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

# link against the boost libraries
target_link_libraries( ${PROJECT_NAME}
    PRIVATE
        Boost::system
        Boost::thread
)
