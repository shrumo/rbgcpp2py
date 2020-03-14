#!/bin/bash

echo "Running python binding tests"

cd ${0%/*}
../scripts/create_game_library.sh ./breakthrough.rbg
cp ../utils.py ./
python3 breakthrough_perft_test.py 
rm rbg_game*
rm -r __pycache__
rm utils.py

