include_directories(${CMAKE_SOURCE_DIR}/common)

# Création de l'exécutable server.bin
add_executable(server.bin server.c ../common/common.c)

# Définition du répertoire de sortie
set_target_properties(server.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
