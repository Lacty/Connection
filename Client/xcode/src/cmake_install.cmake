# Install script for directory: /Users/yanai/Desktop/Connection/Client/src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/AppNative/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Noncopyable/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Vector/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Color/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Rect/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Key/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Mouse/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Font/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/LoadPath/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Graphic/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Audio/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Random/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/CatmullRom/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/TweakBar/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Utility/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/MainCamera/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Scene/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Fade/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Title/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Game/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Udp/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Tcp/cmake_install.cmake")
  include("/Users/yanai/Desktop/Connection/Client/xcode/src/Network/cmake_install.cmake")

endif()

