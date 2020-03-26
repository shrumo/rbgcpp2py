import rbg_game
import time
import sys
from utils import perft, benchmark

def main():
  benchmark()
  state = rbg_game.new_game_state()
  begin = time.time()
  result = perft(state,3)
  end = time.time()
  print('Calculating perft for depth 3 took',end - begin,'s')
  print('The result is',result[0],'leaves and',result[1],'nodes')
  if result != [11132, 11639]:
    print('TEST FAILED')
    print('Expected 11132 leaves and 11639 nodes') 
  else:
    print('TEST SUCCEEDED')

if __name__ == "__main__":
  main()
