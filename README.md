# rbgcpp2py

Regular Boardgames (rbg) is a language that allows one to define an arbitrary boardgame.
The language syntax is defined in https://arxiv.org/abs/1706.02462.

This is a library to translate rbg games into python libraries, that can efficiently
calculate the available moves of the game.

## Running the code

For example to calculate [perft](https://www.chessprogramming.org/Perft) for chess do:

```
./scripts/create_game_library.sh rbg2cpp/rbgParser/examples/chess.rbg
python3 # The next commands will be in python
import rbg_game
import utils
state = rbg_game.new_game_state()
utils.perft(state,4)
```

## Documentation

The best place listing possible method of the rbg modules is the help of rbg_game modu
le. To find it do:

```
./scripts/create_game_library.sh rbg2cpp/rbgParser/examples/chess.rbg
python3
import rbg_game
help(rbg_game)
```

## Dependencies

* cmake (sudo apt install cmake)
* boost (sudo apt install libboost-dev)
* python-dev (sudo apt install python3-dev)

## Tests

To run tests do:
```
./scripts/test.sh
```


