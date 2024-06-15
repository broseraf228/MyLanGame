#ifndef BS_CHESS_PIECE_Ð
#define BS_CHESS_PIECE_Ð

#include <string>

struct int_vect;

class I_chess_piece
{
public:
	I_chess_piece(int team);

	virtual bool try_move(const int_vect&) = 0;
	virtual bool try_eat(const int_vect&) = 0;

	virtual char get_texture() = 0;

	virtual I_chess_piece* Clone() = 0;

	int team;
};

class chess_piece_pawn : public I_chess_piece
{
public:
	chess_piece_pawn(int team);

	bool try_move(const int_vect&);
	bool try_eat(const int_vect&);

	char get_texture();

	I_chess_piece* Clone();
};

#endif
