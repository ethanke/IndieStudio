# Install script for directory: /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RELEASE")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/IndieStudio.app/Contents/MacOS" TYPE EXECUTABLE FILES "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/build/IndieStudio")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/IndieStudio.app/Contents/MacOS/IndieStudio" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/IndieStudio.app/Contents/MacOS/IndieStudio")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/irrlicht-1.8.4/lib/OSX"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/IndieStudio.app/Contents/MacOS/IndieStudio")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/bullet3-2.83.7/lib/OSX"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/IndieStudio.app/Contents/MacOS/IndieStudio")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/irrBullet/lib/OSX"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/IndieStudio.app/Contents/MacOS/IndieStudio")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/IndieStudio.app/Contents/MacOS/IndieStudio")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
