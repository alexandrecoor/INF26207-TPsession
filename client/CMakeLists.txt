include_directories(${CMAKE_SOURCE_DIR}/common)

# Création de l'exécutable client.bin
add_executable(client.bin client.c ../common/common.c)

# Définition du répertoire de sortie
set_target_properties(client.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
