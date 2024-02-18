cmake_minimum_required(VERSION 3.14)

project(ESEDamageCalc)

file(GLOB_RECURSE ESEDamageCalc_SOURCES "src/*.cpp")
file(GLOB_RECURSE ESEDamageCalc_HEADERS "include/*.h")
set(ESEDamageCalc_FILES ${ESEDamageCalc_SOURCES} ${ESEDamageCalc_HEADERS})


# Unit

add_library(ESEDamageCalc SHARED ${ESEDamageCalc_SOURCES} ${ESEDamageCalc_HEADERS})

target_include_directories(ESEDamageCalc PUBLIC include)

# Link D2MOO
# target_link_libraries(ESEDamageCalc D2Common D2Game)
target_link_libraries(ESEDamageCalc
  PRIVATE
    D2Common
    D2Game
    D2GameObjects
)

target_compile_features(ESEDamageCalc PUBLIC cxx_std_17)

# Include D2MOO's headers
target_include_directories(ESEDamageCalc PRIVATE ${D2MOO_SOURCE_DIR}/include)

function(assign_source_group)
    foreach(FILE ${ESEDamageCalc_FILES})
        # Get the directory of the source file
        get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)

        # Remove common directory prefix to make the group
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

        # Make sure we are using windows slashes
        string(REPLACE "/" "\\" GROUP "${GROUP}")

        source_group("${GROUP}" FILES "${FILE}")
    endforeach()
endfunction()

assign_source_group()