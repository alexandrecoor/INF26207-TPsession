include_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB SERVER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_SOURCE_DIR}/lib/*.c)

add_executable(server.bin ${SERVER_SOURCES})

set_target_properties(server.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
