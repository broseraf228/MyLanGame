#include "chess_piece.hpp"

#include "Game.hpp"

I_chess_piece::I_chess_piece(int team)
{
	this->team = team;
}

chess_piece_pawn::chess_piece_pawn(int team) : I_chess_piece(team)
{

}

bool chess_piece_pawn::try_move(const int_vect&)
{
	return true;
}
bool chess_piece_pawn::try_eat(const int_vect&) 
{
	return true;
}
I_chess_piece* chess_piece_pawn::Clone(){
	return new chess_piece_pawn(team);
}
char chess_piece_pawn::get_texture() {
	return 'p';
}