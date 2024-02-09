# We embed the patching ordinal information directly into the .DLLs

D2MOO_add_detours_patch_to_dll(ESEGame)

#set_property(DIRECTORY ${EseMods_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EseMods)
