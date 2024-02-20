# We embed the patching ordinal information directly into the .DLLs


function(D2MOO_add_detours_patch_to_dll DLLTargetName)
  if(ARGV1)
    set(PatchCppFile ${ARGV1})
    set(PatchRcFile ${ARGV2})
  else()
    set(PatchCppFile "${D2MOO_ORDINALS_VERSION}/${DLLTargetName}.patch.cpp")
    set(PatchRcFile "${D2MOO_ORDINALS_VERSION}/${DLLTargetName}.patch.rc")
  endif()
  if(NOT IS_ABSOLUTE PatchCppFile)
    set(PatchCppFile ${CMAKE_CURRENT_SOURCE_DIR}/${PatchCppFile})
  endif()
  if(NOT IS_ABSOLUTE PatchRcFile)
    set(PatchRcFile ${CMAKE_CURRENT_SOURCE_DIR}/${PatchRcFile})
  endif()
  
  if(NOT EXISTS "${PatchCppFile}")
    return()
  endif()
  
  message(STATUS "[${DLLTargetName}]PatchCppFile: '${PatchCppFile}'")
  
  target_sources(${DLLTargetName} PRIVATE "${PatchCppFile}")
  if(EXISTS "${PatchRcFile}")
    target_sources(${DLLTargetName} PRIVATE "${PatchRcFile}")
    message(STATUS "[${DLLTargetName}]PatchRcFile: '${PatchRcFile}'")
  endif()
  target_link_libraries(${DLLTargetName} PRIVATE D2.Detours)
  add_dependencies(${DLLTargetName} D2.DetoursLauncher)

  set_target_properties(${DLLTargetName}
    PROPERTIES
      VS_DEBUGGER_COMMAND $<TARGET_FILE:D2.DetoursLauncher>
      VS_DEBUGGER_ENVIRONMENT "DIABLO2_PATCH=$<TARGET_FILE_DIR:${DLLTargetName}>"
  )

  if(D2_EXE)
    set_target_properties(${DLLTargetName} 
      PROPERTIES 
        VS_DEBUGGER_COMMAND_ARGUMENTS "\"${D2_EXE}\""
        VS_DEBUGGER_WORKING_DIRECTORY "${D2_PATH}"
    )
  endif()
  
  if(NOT D2MOO_CHILD_PROCESS_DBG_SETTINGS_COPIED)
    if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.21.0") # Needed for COPY_FILE and CMAKE_CURRENT_FUNCTION_LIST_DIR requires 3.17
      file(COPY_FILE "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/D2MOO.ChildProcessDbgSettings" "${CMAKE_BINARY_DIR}/D2MOO.ChildProcessDbgSettings")
    endif()
    set(D2MOO_CHILD_PROCESS_DBG_SETTINGS_COPIED TRUE CACHE INTERNAL "")
  endif()

endfunction()


D2MOO_add_detours_patch_to_dll(ESEDamageCalc)

#set_property(DIRECTORY ${EseMods_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EseMods)

