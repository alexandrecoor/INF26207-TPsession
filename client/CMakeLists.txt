include_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB CLIENT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_SOURCE_DIR}/lib/*.c)

add_executable(client.bin ${CLIENT_SOURCES})

set_target_properties(client.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
