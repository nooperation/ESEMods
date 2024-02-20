project(D2MOOHeaders)

file(GLOB_RECURSE D2MOOHeaders_SOURCES "src/*.cpp")
file(GLOB_RECURSE D2MOOHeaders_HEADERS "include/*.h" "include/*.hpp")
set(D2MOOHeaders_FILES ${D2MOOHeaders_SOURCES} ${D2MOOHeaders_HEADERS})

add_library(D2MOOHeaders STATIC ${D2MOOHeaders_SOURCES} ${D2MOOHeaders_HEADERS})

target_include_directories(D2MOOHeaders 
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
set_target_properties(D2MOOHeaders PROPERTIES LINKER_LANGUAGE cpp)

function(assign_source_group)
    foreach(FILE ${D2MOOHeaders_FILES})
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
