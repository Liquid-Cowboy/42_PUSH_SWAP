#!/bin/bash

FILE="$1"

if [ ! -f "$FILE" ]; then
    echo "Ficheiro não encontrado."
    exit 1
fi

while read -r line; do
    ./push_swap $line | wc -l
done < "$FILE"
