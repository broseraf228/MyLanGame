#ifndef BS_CHESS_PIECE_Ð
#define BS_CHESS_PIECE_Ð

#include <string>

class I_chess_piece
{
public:
	I_chess_piece(int team);

	virtual bool try_move(int start_x, int start_y, int stop_x, int stop_y) = 0;
	virtual bool try_eat(int start_x, int start_y, int stop_x, int stop_y) = 0;

	virtual char get_texture() = 0;

	virtual I_chess_piece* Clone() = 0;

	int team;
	int steps{ 0 } ;
};

class chess_piece_pawn : public I_chess_piece
{
public:
	chess_piece_pawn(int team);

	bool try_move(int start_x, int start_y, int stop_x, int stop_y);
	bool try_eat(int start_x, int start_y, int stop_x, int stop_y);

	char get_texture();

	I_chess_piece* Clone();
};

#endif
