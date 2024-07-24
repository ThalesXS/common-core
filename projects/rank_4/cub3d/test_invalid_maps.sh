#!/bin/bash

NAME="cub3d"
MAP_DIR="maps/invalid"

if [ ! -d "$MAP_DIR" ]; then
  echo "Directory $MAP_DIR not founded!"
  exit 1
fi

for map in "$MAP_DIR"/*.cub; do
  if [ -f "$map" ]; then
    echo "███████████"
    printf "█ \e[1mValgrind on: \e[4m$map\e[0m\n"
    VALGRIND_OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all ./$NAME "$map" 2>&1)
    HEAP_USAGE=$(echo "$VALGRIND_OUTPUT" | grep "total heap usage" | awk -v ORS='' '{print "\n█ MEMORY: " $7 "/" $5} {if ($5 == $7) print " \e[1;32mOK\e[0m"; else print " \e[4;31mNOK\e[0m"}')
    ERROR_OUTPUT=$(echo "$VALGRIND_OUTPUT" | grep -A 1 "Error" | awk -v ORS='\n█ ' '{print}')
    echo -e "█ $ERROR_OUTPUT$HEAP_USAGE\n███████████\n"
  fi
done

echo "TEST FINISHED"