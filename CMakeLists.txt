cmake_minimum_required(VERSION 3.10)
project(DigitalEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optionally suppress CMake regeneration to avoid ZERO_CHECK project
set(CMAKE_SUPPRESS_REGENERATION TRUE)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/**/*.cpp" "src/**/*.h" "src/**/*.c")

# Explicitly add main.cpp to ensure it's included in the build
list(APPEND SOURCES "src/main.cpp")

# Find all 'Public' directories and add them to the include path
file(GLOB_RECURSE PUBLIC_DIRS LIST_DIRECTORIES true "src/*/Public/")

# Add executable for the DigitalEngine target
add_executable(DigitalEngine ${SOURCES})

# Add GLFW as a subdirectory
add_subdirectory(third_party/glfw)

# Add all 'Public' directories to the include path
foreach(PUBLIC_DIR ${PUBLIC_DIRS})
    target_include_directories(DigitalEngine PRIVATE ${PUBLIC_DIR})
endforeach()

# Linking process
target_link_libraries(DigitalEngine glfw)

target_link_libraries(DigitalEngine glfw OpenGL32)

# Ensure GLFW include path is added
target_include_directories(DigitalEngine PRIVATE third_party/glfw/include)

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
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DigitalEngine)

