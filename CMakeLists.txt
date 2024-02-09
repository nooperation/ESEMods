cmake_minimum_required(VERSION 3.15)

project(ESEMods)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


set(ENABLE_D2DETOURS_EMBEDDED_PATCHES ON)

set(CMAKE_FOLDER D2MOO)
add_subdirectory(external/d2moo)

set(CMAKE_FOLDER )
add_subdirectory(source/ESEGame)


set(ENABLE_D2DETOURS_EMBEDDED_PATCHES ON)
set(D2DETOURS_EMBEDDED_PATCHES_DIR "D2.Detours.patches" CACHE PATH "The directory to your D2.Detours embedded patches. Defaults to the root D2.Detours.patches directory")
add_subdirectory(${D2DETOURS_EMBEDDED_PATCHES_DIR} ${D2DETOURS_EMBEDDED_PATCHES_BINARY_DIR})

