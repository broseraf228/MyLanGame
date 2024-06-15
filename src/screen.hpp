#ifndef BS_SCREEN_H
#define BS_SCREEN_H

#include "string"
#include "map"

struct geme_drawable_data;

class Screen {
	static Screen* _self;
private:
	Screen(int size_x, int size_y);

	inline int cord(int px, int py);

	int window_size_x, window_size_y;

	std::string buffer;

	static std::map<char, std::string> cheeses_textures;
public:
	Screen(const Screen& obj) = delete;

	static Screen* get();
	static int Initialization();

	void clear();
	void draw(const std::string& str);
	void draw_game(const geme_drawable_data&);
	void display();

	int getSizeX();
	int getSizeY();
};


#endif
