cmake_minimum_required(VERSION 3.10)
project(DigitalEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optionally suppress CMake regeneration to avoid ZERO_CHECK project
set(CMAKE_SUPPRESS_REGENERATION TRUE)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/**/*.cpp" "src/**/*.h")

# Explicitly add main.cpp to ensure it's included in the build
list(APPEND SOURCES "src/main.cpp")

# Find all 'Public' directories and add them to the include path
file(GLOB_RECURSE PUBLIC_DIRS LIST_DIRECTORIES true "src/*/Public")

foreach(PUBLIC_DIR ${PUBLIC_DIRS})
    include_directories(${PUBLIC_DIR})
endforeach()

# Add executable
add_executable(DigitalEngine ${SOURCES})

# Maintain the folder structure in Visual Studio
foreach(FILE ${SOURCES})
    # Extract the folder path of each file
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    
    # Remove the source directory path prefix
    string(REPLACE "${CMAKE_SOURCE_DIR}/" "" GROUP_PATH "${PARENT_DIR}")

    # Assign files to the correct source group (Visual Studio filters)
    source_group("${GROUP_PATH}" FILES "${FILE}")
endforeach()

# Optionally exclude 'ALL_BUILD' and 'ZERO_CHECK' from Visual Studio Solution Explorer
# If you want to use this solution, you can remove 'ALL_BUILD' and 'ZERO_CHECK' manually from Visual Studio after the project is generated
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT My3DEngine)

