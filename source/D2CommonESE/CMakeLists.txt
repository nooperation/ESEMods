cmake_minimum_required(VERSION 3.14)

project(D2CommonESE)

file(GLOB_RECURSE D2CommonESE_SOURCES "src/*.cpp" "D2.Detours.patches/*.cpp" "D2.Detours.patches/*.rc")
file(GLOB_RECURSE D2CommonESE_HEADERS "include/*.h" "include/*.hpp")
set(D2CommonESE_FILES ${D2CommonESE_SOURCES} ${D2CommonESE_HEADERS})


# Unit

add_library(D2CommonESE SHARED ${D2CommonESE_SOURCES} ${D2CommonESE_HEADERS})

target_include_directories(D2CommonESE PUBLIC include)

# Link D2MOO
target_link_libraries(D2CommonESE D2MOOHeaders D2.Detours ESECommon)
add_dependencies(D2CommonESE D2.DetoursLauncher ESECommon)

target_compile_features(D2CommonESE PUBLIC cxx_std_17)

# Include D2MOO's headers
target_include_directories(D2CommonESE 
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
		${ESECommon_SOURCE_DIR}/include
)

set_target_properties(D2CommonESE
	PROPERTIES
	VS_DEBUGGER_COMMAND $<TARGET_FILE:D2.DetoursLauncher>
	VS_DEBUGGER_ENVIRONMENT "DIABLO2_PATCH=$<TARGET_FILE_DIR:D2CommonESE>"
)

if(D2_EXE)
	set_target_properties(D2CommonESE 
		PROPERTIES 
		VS_DEBUGGER_COMMAND_ARGUMENTS "\"${D2_EXE}\""
		VS_DEBUGGER_WORKING_DIRECTORY "${D2_PATH}"
	)
endif()

function(assign_source_group)
    foreach(FILE ${D2CommonESE_FILES})
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