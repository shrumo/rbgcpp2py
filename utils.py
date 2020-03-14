import rbg_game

bitarraystack = rbg_game.resettable_bitarray_stack()

# This modifies the input state. Calculates the keeper closure on the given state.
def keeper_closure(state):
  move_exists = True
  while state.get_current_player() == 0 and move_exists:
    move_exists = state.apply_any_move(bitarraystack)

# Visits all the game tree of a given game to the given depth
# Returns a pair of numbers of leaves visited and number of nodes visited
def perft(state, depth):
  if not state:
    return [0,0]
  if depth == 0:
    return [1,1] 
  moves = state.get_all_moves(bitarraystack)
  result = [0,0]
  result[1] += 1
  for move in moves:
    next_state = state.copy()
    next_state.apply_move(move)
    keeper_closure(next_state)
    rec_result = perft(next_state, depth-1)
    result[0] += rec_result[0]
    result[1] += rec_result[1]
  return result
