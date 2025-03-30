cmake_minimum_required(VERSION 3.10)
project(DigitalEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optionally suppress CMake regeneration to avoid ZERO_CHECK project
set(CMAKE_SUPPRESS_REGENERATION TRUE)

#LogMeCPP
set(LOGMECPP_PATH ${CMAKE_SOURCE_DIR}/third_party/externals/LogMeCPP)
set(LOGMECPP_OUTPUT ${LOGMECPP_PATH}/x64/Debug)

#DigitalMath
set(DIGITALMATH_PATH ${CMAKE_SOURCE_DIR}/third_party/externals/DigitalMath)
#set(DIGITAL_MATH_PATH ${CMAKE_SOURCE_DIR}/third_party/externals/DigitalMath)
set(DIGITALMATH_OUTPUT ${DIGITAL_MATH_PATH}/x64/Debug)


# Collect all source files
file(GLOB_RECURSE SOURCES "src/**/*.cpp" "src/**/*.h" "src/**/*.c")
# Collect all source files from DigitalMath
file(GLOB_RECURSE DIGITALMATH_SOURCES
    "${DIGITALMATH_PATH}/src/Private/DigitalMath/*.cpp"
    "${DIGITALMATH_PATH}/src/Public/DigitalMath/*.h"
)

# Explicitly add main.cpp to ensure it's included in the build
list(APPEND SOURCES "src/main.cpp")

# Find all 'Public' directories and add them to the include path
file(GLOB_RECURSE PUBLIC_DIRS LIST_DIRECTORIES true "src/*/Public/")

# Add executable for the DigitalEngine target
add_executable(DigitalEngine ${SOURCES} ${DIGITALMATH_SOURCES})

# Add GLFW as a subdirectory
add_subdirectory(third_party/glfw)

# Include LogMeCPP headers (if needed)
include_directories(${LOGMECPP_PATH})

# Add all 'Public' directories to the include path
foreach(PUBLIC_DIR ${PUBLIC_DIRS})
    target_include_directories(DigitalEngine PRIVATE ${PUBLIC_DIR})
	target_include_directories(DigitalEngine PRIVATE ${DIGITALMATH_PATH}/src/Public)
endforeach()

# Ensure GLFW include path is added
target_include_directories(DigitalEngine PRIVATE third_party/glfw/include)

target_link_libraries(DigitalEngine ${LOGMECPP_OUTPUT}/LogMeCpp.lib glfw OpenGL32)
#target_link_libraries(DigitalEngine ${DIGITALMATH_OUTPUT}/DigitalMath.lib)

# Maintain the folder structure in Visual Studio
foreach(FILE ${SOURCES})
    # Extract the folder path of each file
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    
    # Remove the source directory path prefix
    string(REPLACE "${CMAKE_SOURCE_DIR}/" "" GROUP_PATH "${PARENT_DIR}")

    # Assign files to the correct source group (Visual Studio filters)
    source_group("${GROUP_PATH}" FILES "${FILE}")
endforeach()

foreach(FILE ${DIGITALMATH_SOURCES})
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${DIGITALMATH_PATH}" "src/DigitalMath" GROUP_PATH "${PARENT_DIR}")
    source_group("${GROUP_PATH}" FILES "${FILE}")
endforeach()

# Optionally exclude 'ALL_BUILD' and 'ZERO_CHECK' from Visual Studio Solution Explorer
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DigitalEngine)

# Copy the DLL to the output directory so the engine can find it at runtime
add_custom_command(TARGET DigitalEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${LOGMECPP_OUTPUT}/LogMeCpp.dll
		#${DIGITALMATH_OUTPUT}/DigitalMath.dll
        $<TARGET_FILE_DIR:DigitalEngine>
)

