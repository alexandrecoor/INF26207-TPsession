include_directories(${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/client/include)

file(GLOB CLIENT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_SOURCE_DIR}/lib/*.c)

add_executable(client ${CLIENT_SOURCES})

set_target_properties(client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/..)
