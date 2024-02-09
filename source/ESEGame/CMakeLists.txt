cmake_minimum_required(VERSION 3.14)

project(ESEGame)

file(GLOB ESEGame_SOURCES "src/*.cpp")
file(GLOB ESEGame_HEADERS "include/*.h")

add_library(ESEGame SHARED ${ESEGame_SOURCES} ${ESEGame_HEADERS})

target_include_directories(ESEGame PUBLIC include)

# Link D2MOO
# target_link_libraries(ESEGame D2Common D2Game)
target_link_libraries(ESEGame
  PRIVATE
    D2Common
    D2Game
    D2GameObjects
)

# Include D2MOO's headers
target_include_directories(ESEGame PRIVATE ${D2MOO_SOURCE_DIR}/include)
