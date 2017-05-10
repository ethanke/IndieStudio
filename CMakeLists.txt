# stop if cmake version below 3.3
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# project name
project(IndieStudio)


# project version
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
string(STRIP ${PROJECT_SOURCE_DIR} SOURCES_PATH)


# location of additional cmake modules
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake
)


# guard against in-source builds and bad build-type strings
include(safeguards)


# detect operating system
message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_definitions(-DSYSTEM_LINUX)
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    add_definitions(-DSYSTEM_DARWIN)
endif()
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(-DSYSTEM_WINDOWS)
endif()


# detect host processor
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")


# example how to set c++ compiler flags for GNU
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
    set(CMAKE_CXX_FLAGS         "-std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3 -DDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
elseif(CMAKE_CXX_COMPILER_ID MATCHES Clang)
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
    set(CMAKE_CXX_FLAGS         "-std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3 -DDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

# settings library dependencies
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    link_directories(${PROJECT_SOURCE_DIR}/lib/irrlicht-1.8.4/lib/OSX/)
    link_directories(${PROJECT_SOURCE_DIR}/lib/bullet3-2.83.7/lib/OSX/)
    link_directories(${PROJECT_SOURCE_DIR}/lib/irrBullet/lib/OSX)
endif()
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    link_directories(${PROJECT_SOURCE_DIR}/lib/irrlicht-1.8.4/lib/Win64-visualStudio/)
endif()


set(SRC_FILES
    ${PROJECT_SOURCE_DIR}/sources/main.cpp
    ${PROJECT_SOURCE_DIR}/sources/FolderLoader.cpp
    ${PROJECT_SOURCE_DIR}/sources/AGame.cpp
    ${PROJECT_SOURCE_DIR}/sources/IndieGame.cpp
    ${PROJECT_SOURCE_DIR}/sources/AGameObject.cpp
    ${PROJECT_SOURCE_DIR}/sources/GameCube.cpp
    ${PROJECT_SOURCE_DIR}/sources/AGameCamera.cpp
    ${PROJECT_SOURCE_DIR}/sources/GameCameraFPS.cpp
    ${PROJECT_SOURCE_DIR}/sources/EventReceiver.cpp
    ${PROJECT_SOURCE_DIR}/sources/AModelObject.cpp
    ${PROJECT_SOURCE_DIR}/sources/APhysicObject.cpp
    ${PROJECT_SOURCE_DIR}/sources/CarModel.cpp
)

# build executable
add_executable(IndieStudio ${SRC_FILES})


# settings library dependencies
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME}
        Irrlicht
    )
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME}
        Irrlicht
        irrBullet
        BulletSoftBody
        BulletDynamics
        BulletCollision
        LinearMath
        boost_system
        boost_filesystem
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework Carbon"
    )
endif()
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_link_libraries(${PROJECT_NAME}
        Irrlicht
    )
endif()


# location of header files
include_directories(
    ${PROJECT_BINARY_DIR}/includes
    ${PROJECT_SOURCE_DIR}/includes
    ${PROJECT_SOURCE_DIR}/lib/irrlicht-1.8.4/include/
    ${PROJECT_SOURCE_DIR}/lib/irrBullet/include/
    ${PROJECT_SOURCE_DIR}/lib/bullet3-2.83.7/include/bullet/
)


# configure header file
configure_file(
    ${PROJECT_SOURCE_DIR}/CMake/config.h.in
    ${PROJECT_BINARY_DIR}/includes/IndieStudioConfig.h
)


# install binary
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
        SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})
    ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    install(TARGETS IndieStudio DESTINATION IndieStudio.app/Contents/MacOS)
endif()
