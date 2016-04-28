
# --- Set include directories
#
include_directories(
  ${CMAKE_SOURCE_DIR}/include
)


# --- Set compile options
#
if(APPLE)
  set(CMAKE_C_FLAGS "-Wall -g")
  add_definitions("-std=c++14")
endif()

# --- Set Source Files to Project
#
add_executable(Connection main.cpp)


# --- Find Libraries
#
if (APPLE)
  find_library(COCOA_LIBRARY     Cocoa)
  find_library(OpenGL_LIBRARY    OpenGL)
  find_library(OpenAL_LIBRARY    OpenAL)
  find_library(IOKIT_LIBRARY     IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)
  set(EXTRA_LIBS
    ${COCOA_LIBRARY}
    ${OpenGL_LIBRARY}
    ${OpenAL_LIBRARY}
    ${IOKIT_LIBRARY}
    ${COREVIDEO_LIBRARY}
    ${CMAKE_SOURCE_DIR}/lib/OSX/libglfw3.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libfreetyped.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libFTGL.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libAntTweakBar.a
  )
elseif(MSVC)
  set(EXTRA_LIBS
    ${CMAKE_SOURCE_DIR}/lib/Windows/OpenGL32.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/freetype.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/ftgld.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/glfw3d.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/AntTweakBar64.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/OpenAL32.lib
    ws2_32.lib
  )
endif()


# --- Add My Libraries
#
set(MY_LIBS
  AppNative
  Noncopyable
  Vector
  Color
  Rect
  Key
  Mouse
  Font
  LoadPath
  Graphic
  Audio
  Random
  CatmullRom
  TweakBar
  Utility
  MainCamera
  Scene
  Fade
  Title
  Game
  Udp
  Tcp
  Network
)
foreach(loop_var IN LISTS MY_LIBS)
  add_subdirectory(${loop_var})
endforeach()


# --- Set Library to project
#
target_link_libraries(Connection ${MY_LIBS} ${EXTRA_LIBS})


# --- copy Static Libraries to dir[vs2015/src/Debug]
#
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/vs2015/src/Debug)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/vs2015/src/Release)
set(STATIC_LIBS
  ${CMAKE_SOURCE_DIR}/lib/Windows/AntTweakBar64.dll
  ${CMAKE_SOURCE_DIR}/lib/Windows/OpenAL32.dll
  ${CMAKE_SOURCE_DIR}/lib/Windows/wrap_oal.dll
)
foreach(loop_var IN LISTS STATIC_LIBS)
  execute_process(COMMAND
    ${CMAKE_COMMAND} -E
    copy ${loop_var}
         ${CMAKE_SOURCE_DIR}/vs2015/src/Debug
  )
  execute_process(COMMAND
    ${CMAKE_COMMAND} -E
    copy ${loop_var}
         ${CMAKE_SOURCE_DIR}/vs2015/src/Release
  )
endforeach()
