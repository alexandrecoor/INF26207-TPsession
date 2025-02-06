#!/bin/bash

BUILD_DIR="build"
BIN_DIR="bin"

if [ -d "$BUILD_DIR" ]; then
    echo "🗑️ Suppression du dossier $BUILD_DIR..."
    rm -rf "$BUILD_DIR"
    if [ $? -ne 0 ]; then exit 1; fi
fi

mkdir -p "$BUILD_DIR"
mkdir -p "$BIN_DIR"

cd "$BUILD_DIR" || exit

cmake -DCMAKE_BUILD_TYPE=Release ..
if [ $? -ne 0 ]; then exit 1; fi

cmake --build .
if [ $? -ne 0 ]; then exit 1; fi

cd ..

if [ ! -f "./bin/server.bin" ]; then
    echo "❌ Erreur : bin/server.bin introuvable !"
    exit 1
fi

if [ ! -f "./bin/client.bin" ]; then
    echo "❌ Erreur : bin/client.bin introuvable !"
    exit 1
fi

rm -rf "$BUILD_DIR"

echo "=============================================="
echo "✅ Compilation terminée avec succès !"
echo "🏁 Fichiers générés dans bin/"
echo "=============================================="
exit 0
