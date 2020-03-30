#!/bin/bash

echo "Running python binding tests"

cd ${0%/*}
./create_game_library.sh ../tests/breakthrough.rbg
mv rbg_game* ../build/
cp ../utils.py ../build/
cp ../tests/breakthrough_perft_test.py ../build/
cd ../build
python3 breakthrough_perft_test.py 
rm rbg_game*
rm -r __pycache__
rm utils.py

