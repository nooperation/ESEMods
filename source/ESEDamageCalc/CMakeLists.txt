cmake_minimum_required(VERSION 3.14)

project(ESEDamageCalc)

file(GLOB_RECURSE ESEDamageCalc_SOURCES "src/*.cpp")
file(GLOB_RECURSE ESEDamageCalc_HEADERS "include/*.h" "include/*.hpp")
set(ESEDamageCalc_FILES ${ESEDamageCalc_SOURCES} ${ESEDamageCalc_HEADERS})


# Unit

add_library(ESEDamageCalc SHARED ${ESEDamageCalc_SOURCES} ${ESEDamageCalc_HEADERS})

target_include_directories(ESEDamageCalc PUBLIC include)

# Link D2MOO
target_link_libraries(ESEDamageCalc D2MOOHeaders)

target_compile_features(ESEDamageCalc PUBLIC cxx_std_17)

# Include D2MOO's headers
target_include_directories(ESEDamageCalc 
	PRIVATE
		${D2MOOHeaders_SOURCE_DIR}/include/D2CMP
		${D2MOOHeaders_SOURCE_DIR}/include/D2Common
		${D2MOOHeaders_SOURCE_DIR}/include/D2CommonDefinitions
		${D2MOOHeaders_SOURCE_DIR}/include/D2Game
		${D2MOOHeaders_SOURCE_DIR}/include/D2Gfx
		${D2MOOHeaders_SOURCE_DIR}/include/D2Hell
		${D2MOOHeaders_SOURCE_DIR}/include/D2Lang
		${D2MOOHeaders_SOURCE_DIR}/include/D2MCPClient
		${D2MOOHeaders_SOURCE_DIR}/include/D2Net
		${D2MOOHeaders_SOURCE_DIR}/include/D2Sound
		${D2MOOHeaders_SOURCE_DIR}/include/D2Win
		${D2MOOHeaders_SOURCE_DIR}/include/Fog
		${D2MOOHeaders_SOURCE_DIR}/include/Game
		${D2MOOHeaders_SOURCE_DIR}/include/Storm
)

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