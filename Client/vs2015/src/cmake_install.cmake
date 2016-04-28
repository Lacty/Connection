# Install script for directory: C:/Users/USER/Desktop/Connection/Client/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/Connection")
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
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/AppNative/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Noncopyable/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Vector/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Color/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Rect/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Key/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Mouse/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Font/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/LoadPath/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Graphic/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Audio/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Random/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/CatmullRom/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/TweakBar/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Utility/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/MainCamera/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Scene/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Fade/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Title/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Game/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Udp/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Tcp/cmake_install.cmake")
  include("C:/Users/USER/Desktop/Connection/Client/vs2015/src/Network/cmake_install.cmake")

endif()

