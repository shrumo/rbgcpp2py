
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include "rbg_game.hpp"

namespace py = pybind11;

PYBIND11_MODULE(rbg_game, m) {
  m.doc() = 
R"pbdoc(
rbg_game module contains a simple interface
to a compiled rbg game.
-----------------------
)pbdoc";


m.def("board_size",[](){return rbg_game::BOARD_SIZE;},"Size of the board for the game. This is the number of nodes in the grap defining the board. The index of a node is a number from 0 to board_size - 1. (inclusive) For example for chess.rbg this would be 64.");
m.def("number_of_players",[](){return rbg_game::NUMBER_OF_PLAYERS;}, "Number of players participating in the game. Players have numbers from 1 to this number-1. (inclusive) The keeper player has number 0. For example for chess.rbg this would be 3 (two players plus keeper).");
m.def("number_of_pieces",[](){return rbg_game::NUMBER_OF_PIECES;}, "Number of pieces in the game. Pieces have numbers from 1 to this number. (inclusive)");
m.def("number_of_variables",[](){return rbg_game::NUMBER_OF_VARIABLES;}, "Number of variables in the game. Variables have numbers from 0 to this number-1. (inclusive)");
m.def("board_degree",[](){return rbg_game::BOARD_DEGREE;});
m.def("monotonic_classes",[](){return rbg_game::MONOTONIC_CLASSES;});

m.def("board_cell_to_string",&rbg_game::board_cell_to_string,"Translates a board node to a string representation of it. Usually the string representation contains a humand readable description of what the node is in context of the game. For example for chess.rbg, rbg_game.board_cell_to_string(0) == 'rx0y0'");
m.def("piece_to_string",&rbg_game::piece_to_string,"Translates a piece number to a string representation of it. For example for chess.rbg, rbg_game.piece_to_string(0) == 'blackBishop'");
m.def("variable_to_string",&rbg_game::variable_to_string,"Translates variables names to some meaningful name. For example for chess.rbg, rbg_game.variable_to_string(2) == 'blackKindMoved'.");
m.def("number_of_modifiers",[](){return rbg_game::NUMBER_OF_MODIFIERS;});
m.def("action_to_modifier_index",&rbg_game::action_to_modifier_index);
m.def("modifier_to_action_index",&rbg_game::modifier_to_action_index);
m.def("get_neighbour",&rbg_game::get_neighbor,"Returns the next node of the board node, when applying the given edge.");
m.def("get_bound",&rbg_game::get_bound,"Returns the bound of the variable.");

pybind11::class_<rbg_game::resettable_bitarray_stack>(m,"resettable_bitarray_stack")
  .def(py::init<>());
pybind11::class_<rbg_game::action_representation>(m,"action_representation")
  .def_readonly("index",&rbg_game::action_representation::index,"The index of the rule to be applied.")
  .def_readonly("cell",&rbg_game::action_representation::cell,"The cell the rule should be applied at.");
pybind11::class_<rbg_game::move>(m,"move")
  .def_readonly("mr",&rbg_game::move::mr);
pybind11::class_<rbg_game::game_state>(m,"game_state")
  .def(py::init<>())
  .def("copy",[](const rbg_game::game_state& state){return rbg_game::game_state(state);}, "Creates a copy of the current game_state.")
  .def("get_current_cell",&rbg_game::game_state::get_current_cell,"Returns the cell the game_state points at.")
  .def("get_piece",&rbg_game::game_state::get_piece)
  .def("get_variable_value",&rbg_game::game_state::get_variable_value)
  .def("get_current_player",&rbg_game::game_state::get_current_player)
  .def("get_player_score",&rbg_game::game_state::get_player_score)
  .def("apply_move",&rbg_game::game_state::apply_move)
  .def("get_all_moves",py::overload_cast<rbg_game::resettable_bitarray_stack&>(&rbg_game::game_state::get_all_moves))
  .def("apply_any_move",&rbg_game::game_state::apply_any_move)
  .def("is_legal",&rbg_game::game_state::is_legal);
};
