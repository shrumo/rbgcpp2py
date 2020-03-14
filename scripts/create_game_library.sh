#!/bin/bash

# This create the rbg_game library for the give game
# This file must be in the scripts directory. 
# (It relies on the structure of the project being specific relative to this directory.)

echo "Creating rbg_game python library for $1"

git submodule init --recursive
git submodule update --recursive

make --directory=${0%/*}/../rbg2cpp
${0%/*}/../rbg2cpp/bin/rbg2cpp -o rbg_game $1
mv ./rbg_game.cpp ${0%/*}/../rbg_game.cpp
mv ./rbg_game.hpp ${0%/*}/../rbg_game.hpp
cmake .. -B ${0%/*}/../build
make --directory=${0%/*}/../build
rm ${0%/*}/../rbg_game.cpp
rm ${0%/*}/../rbg_game.hpp
cp ${0%/*}/../build/rbg_game* ./
