# Install script for directory: /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/CommonDialogs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/build/lib/libCEGUICommonDialogs-0.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCEGUICommonDialogs-0.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCEGUICommonDialogs-0.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCEGUICommonDialogs-0.dylib")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI/CommonDialogs" TYPE FILE FILES "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/CommonDialogs/../../include/CEGUI/CommonDialogs/Module.h")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI/CommonDialogs/ColourPicker" TYPE FILE FILES
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/CommonDialogs/../../include/CEGUI/CommonDialogs/ColourPicker/ColourPicker.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/CommonDialogs/../../include/CEGUI/CommonDialogs/ColourPicker/Controls.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/CommonDialogs/../../include/CEGUI/CommonDialogs/ColourPicker/Conversions.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/CommonDialogs/../../include/CEGUI/CommonDialogs/ColourPicker/Types.h"
    )
endif()

