cmake_minimum_required(VERSION 3.14)

project(ESEDamageCalc)

file(GLOB ESEDamageCalc_SOURCES "src/*.cpp")
file(GLOB ESEDamageCalc_HEADERS "include/*.h")

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
