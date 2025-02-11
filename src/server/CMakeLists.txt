include_directories(${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/server/include)

file(GLOB SERVER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_SOURCE_DIR}/lib/*.c)

add_executable(server ${SERVER_SOURCES})

set_target_properties(server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/..)

target_link_libraries(server uuid)
