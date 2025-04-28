#main file

# Specify default build type if none provided (before project() command)
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# For generators with multiple configurations (like VS), only allow Debug and Release
if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Limited configurations" FORCE)
	mark_as_advanced(CMAKE_CONFIGURATION_TYPES)
endif()


cmake_minimum_required(VERSION 3.31.5)
project(DanGame LANGUAGES CXX)

include(GetSFML.txt)


#CheckIncludeFile

# build output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(CMAKE_PDB_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH $<0:>${CMAKE_BINARY_DIR}/bin)

# cpp standard options
set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 17)

#enable console logging
if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_definitions(-DENABLE_LOG)
endif()

#gather source files
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE inlines ${CMAKE_CURRENT_SOURCE_DIR}/include/*.inl)
add_executable(${PROJECT_NAME} ${sources} ${headers} ${inlines})

#add_executable(${PROJECT_NAME})
#include directories
#add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PRIVATE
#    ${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/core
	${CMAKE_CURRENT_SOURCE_DIR}/src/states
	${CMAKE_CURRENT_SOURCE_DIR}/src/game
	${CMAKE_CURRENT_SOURCE_DIR}/src/ui
#    ${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/core
	${CMAKE_CURRENT_SOURCE_DIR}/include/states
	${CMAKE_CURRENT_SOURCE_DIR}/include/game
	${CMAKE_CURRENT_SOURCE_DIR}/include/ui
)
#copy media file from source dir to build dir
file(COPY ${CMAKE_SOURCE_DIR}/Media DESTINATION ${CMAKE_BINARY_DIR}/bin)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

#link the different libraries into the executable
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::System SFML::Graphics)

