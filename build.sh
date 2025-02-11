#!/bin/bash

BUILD_DIR="build"
CLIENT_BIN="client"
SERVER_BIN="server"

cleanup() {
    if [[ "$(pwd)" =~ /${BUILD_DIR}$ ]]; then
        cd ..
    fi
    echo "🗑️ Suppression du dossier $BUILD_DIR..."
    rm -rf "$BUILD_DIR"
}

trap cleanup EXIT

if [ -d "$BUILD_DIR" ]; then
    cleanup
fi

if [ -f "$CLIENT_BIN" ]; then
    rm $CLIENT_BIN
fi

if [ -f "$SERVER_BIN" ]; then
    rm $SERVER_BIN
fi

mkdir -p "$BUILD_DIR"

cd "$BUILD_DIR" || exit 1

cmake -DCMAKE_BUILD_TYPE=Release ../src
if [ $? -ne 0 ]; then exit 1; fi

cmake --build .
if [ $? -ne 0 ]; then exit 1; fi

cd ..

if [ ! -f "./server" ]; then
    echo "❌ Erreur : server introuvable !"
    exit 1
fi

if [ ! -f "./client" ]; then
    echo "❌ Erreur : client introuvable !"
    exit 1
fi

echo "=============================================="
echo "✅ Compilation terminée avec succès !"
echo "🏁 Fichiers générés : ./client et ./server"
echo "=============================================="
exit 0
