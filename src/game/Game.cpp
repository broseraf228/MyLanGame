#include "Game.hpp"

#include <iostream>

std::vector<std::vector<I_chess_piece*>> Game::default_map
{ 
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr}
};

Game* Game::_self = nullptr;
Game* Game::get()
{
	if (_self == nullptr)
		Initialization();
	return _self;
}

bool Game::inmap(int x, int y)
{
	if (x < 0 || x >= game_map.size())
		return false;
	if (y < 0 || y >= game_map[x].size())
		return false;
	return true;
}

void Game::fill_map_to_default()
{
	int sx = default_map.size(), sy = 0;
	game_map.resize(sx);
	for (int i = 0; i < sx;  i++) {
		sy = default_map[i].size();

		game_map[i].resize(sy, nullptr);
		for (int j = 0; j < sy; j++ )
		{
			delete game_map[i][j];
			if (default_map[i][j] == nullptr) {
				game_map[i][j] = nullptr;
				continue;
			}
			game_map[i][j] = default_map[i][j]->Clone();
		}
	}
}
Game::Game() {
	last_command = "";

	fill_map_to_default();
	drawable_data.map.resize(default_map[0].size(), std::string("?", default_map.size()));
}
int Game::Initialization() {
	if (_self != nullptr) {
		return 0;
	}

	_self = new Game();
	return 0;
}

int Game::step(const std::string& input) {
	last_command = input;

	int ans = 0;

	if (input.size() != 4) { ans = 1; goto RR; }

	int ax = input[0] - '0' - 1, ay = input[1] - '0' - 1, bx = input[2] - '0' - 1, by = input[3] - '0' - 1;
	if (!inmap(ax, ay)) { ans = 2; goto RR; }
	if (!inmap(bx, by)) { ans = 2; goto RR; }

	if (game_map[ax][ay] == nullptr) { ans = 3; goto RR; }

	if (game_map[bx][by] == nullptr) // can move on free place?
		if (game_map[ax][ay]->try_move( ax, ay, bx, by ) )
		{
			
			game_map[bx][by] = game_map[ax][ay];
			game_map[ax][ay] = nullptr;
			ans = 0; goto RR;
		}
		else { ans = 4; goto RR; }

	if (game_map[bx][by] != nullptr) // can eat figure on place?
		if (game_map[ax][ay]->try_eat(ax, ay, bx, by) )
		{
			delete game_map[bx][by];
			game_map[bx][by] = game_map[ax][ay];
			game_map[ax][ay] = nullptr;
			ans = 0; goto RR;
		}
		else { ans = 5; goto RR; }

		
RR:
	// map drawing
	int sx = game_map.size(), sy = game_map[0].size();
	for (int x = 0; x < sx; x++) {
		for (int y = 0; y < sy; y++)
		{
			if (game_map[x][y] == nullptr) {
				drawable_data.map[y][x] = (x+y) % 2 == 0 ? '8': '9';
				continue;
			}
			drawable_data.map[y][x] = game_map[x][y]->get_texture();
		}
	}

	switch (ans)
	{
	case 0:
		drawable_data.answer = "";
		step_counter++;
		return 0;
	case 1:
		drawable_data.answer = "unvailid input, try again like <0104>";
		return 1;
	case 2:
		drawable_data.answer = "unvailid input - position out of map";
		return 2;
	case 3:
		drawable_data.answer = "<" + std::to_string(ax + 1) + " " + std::to_string(ay + 1) + "> is empty";
		return 3;
	case 4:
		drawable_data.answer = "figure cant move on <" + std::to_string(bx + 1) + " " + std::to_string(by + 1) + ">";
		return 4;
	case 5:
		drawable_data.answer = "figure cant eat figure on <" + std::to_string(bx + 1) + " " + std::to_string(by + 1) + ">";
		return 5;
	default:
		drawable_data.answer = "unknown error";
		return -1;
	}
}

const geme_drawable_data& Game::get_drawable_data(){
	return drawable_data;
}
const std::vector<std::vector<I_chess_piece*>>& Game::get_map(){
	return game_map;
}
int Game::get_step_count(){
	return step_counter;
}