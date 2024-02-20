cmake_minimum_required(VERSION 3.15)

project(ESEMods)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(BUILD_SHARED_LIBS ON CACHE BOOL "Should we build shared libraries (.DLLs) instead of static libraries.")

set(CMAKE_FOLDER D2MOOHeaders)
add_subdirectory(external/D2MOOHeaders)

set(BUILD_SHARED_LIBS_BACKUP ${BUILD_SHARED_LIBS})
set(BUILD_SHARED_LIBS OFF) # Build external libs as static libs (or their default settings) for now 

set(CMAKE_FOLDER external)
add_subdirectory(external/D2.Detours)

# Restore BUILD_SHARED_LIBS
set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS_BACKUP})

# Look for D2SE first, then Diablo II.
find_program(D2_EXE NAMES D2SE.exe "Game.exe" "Diablo II.exe"
  HINTS $ENV{D2INSTALL} $ENV{D2SE}
  PATH_SUFFIXES "Diablo II"
)

if(D2_EXE)
	get_filename_component(D2_PATH ${D2_EXE} DIRECTORY CACHE)
else()
	message(STATUS "D2 executable was not found, please set the `D2_EXE` CMake variable for debugging if your game executable is not at the install location.")
endif()


set(CMAKE_FOLDER )
add_subdirectory(source/ESECommon)
add_subdirectory(source/D2GameESE)
add_subdirectory(source/D2CommonESE)
