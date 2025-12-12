#!/bin/bash

FILE="$1"

if [ ! -f "$FILE" ]; then
    echo "Ficheiro não encontrado."
    exit 1
fi

while read -r line; do
    echo "Testando: $line"
    ./push_swap $line | ./checker_linux $line
    echo
done < "$FILE"
