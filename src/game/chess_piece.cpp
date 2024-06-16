#include "chess_piece.hpp"

#include "Game.hpp"

Game* game = Game::get();

I_chess_piece::I_chess_piece(int team)
{
	this->team = team;
}

chess_piece_pawn::chess_piece_pawn(int team) : I_chess_piece(team)
{

}
bool chess_piece_pawn::try_move(int ax, int ay, int bx, int by)
{
	//MOVING
	int dx = abs(ax - bx), dy = abs(ay - by);

	if (dx != 0) goto CP_P_B;
	if (dx == 0 && dy == 0) goto CP_P_B;

	if(steps == 0)
	{
		if (dy <= 2) goto CP_P_G;
		goto CP_P_B;
	}
	else
	{
		if (dy == 1) goto CP_P_G;
		goto CP_P_B;
	}

CP_P_B:
	return false;
CP_P_G:
	steps++;
	return true;
}
bool chess_piece_pawn::try_eat(int ax, int ay, int bx, int by)
{
	//EATING
	int dx = abs(ax - bx), dy = abs(ay - by);

	if (dx == 0 && dy == 0) goto CP_P_B;

	if (dy == 1 && dx == 1) goto CP_P_G;
	goto CP_P_B;


CP_P_B:
	return false;
CP_P_G:
	if(game->get_map()[bx][by]->team == this->team) goto CP_P_B;
	steps++;
	return true;
}
I_chess_piece* chess_piece_pawn::Clone(){
	return new chess_piece_pawn(team);
}
char chess_piece_pawn::get_texture() {
	return 'p';
}