cmake_minimum_required(VERSION 3.17)
project(tboiTEST)

set(CMAKE_CXX_STANDARD 14)
#Configure files here

configure_file(images/penguinCut.png images/penguinCut.png COPYONLY)
configure_file(images/tbioBackground.png images/tbioBackground.png COPYONLY)
configure_file(images/openDoor.png images/openDoor.png COPYONLY)

set(EXECUTABLE_NAME "tboiTEST")

add_executable(${EXECUTABLE_NAME} main.cpp "Classes/Entity.cpp" "Classes/Entity.h" Classes/Character.cpp Classes/Character.h Classes/Tear.cpp Classes/Tear.h Classes/CharacterStats.cpp Classes/CharacterStats.h Classes/TearStats.cpp Classes/TearStats.h Classes/dungeonFloor.cpp Classes/dungeonFloor.h Classes/dungeonRoom.cpp Classes/dungeonRoom.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()