
# --- Set include directories
#
include_directories(
  ${CMAKE_SOURCE_DIR}/include
)


# --- Set compile options
#
if (APPLE)
  set(CMAKE_C_FLAGS -Wall)
  add_definitions(-std=c++14)
endif()


# --- Set source files to project
#
add_executable(Server main.cpp)


# --- Add My Libraries
#
set(MY_LIBS
  Udp
)
foreach(loop_var IN LISTS MY_LIBS)
  add_subdirectory(${loop_var})
endforeach()


# --- Find libraries
#
if (MSVC)
  set(EXTRA_LIBS
    ws2_32.lib
  )
endif()


# --- Set libraries to project
#
target_link_libraries(Server ${MY_LIBS} ${EXTRA_LIBS})
