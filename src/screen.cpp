#include "screen.hpp"

#include "game/Game.hpp"

#include <iostream>
#include "Windows.h"

void console_size(int& size_x, int& size_y)
{
    HANDLE hWndConsole;
    if (hWndConsole = GetStdHandle(-12))
    {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
        {
            size_x = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
            size_y = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
        }
        else
            printf("Error: %d\n", GetLastError());
    }
    else
        printf("Error: %d\n", GetLastError());
}

std::map<char, std::string> Screen::cheeses_textures
{
    {' ', "  "},
    {'8', ".."},
    {'9', "[]"},
    {'p', "P "},
};

Screen* Screen::_self = nullptr;
Screen* Screen::get()
{
	if (_self == NULL) 
		throw("screen called without initialising");
	return _self;
}

Screen::Screen(int size_x, int size_y)
{
	window_size_x = size_x;
	window_size_y = size_y;

    clear();
}
int Screen::Initialization()
{
    if (_self != nullptr)
        throw("screen double initialisation");

    int size_x, size_y;
    console_size(size_x, size_y);

	_self = new Screen(size_x, size_y);

	return 0;
}

void Screen::clear()
{
    buffer = "";
}

void Screen::draw(const std::string& str) {
    buffer += str;
}
void Screen::draw_game(const geme_drawable_data& data)
{
    for (auto& item : data.map) {
        for (auto ch : item) {
            buffer += cheeses_textures[ch];
        }
        buffer += '\n';
    }
    buffer += "\n\n\n";
    if(data.answer != "")
        buffer += "error: " + data.answer;
}

void Screen::display() 
{
    system("cls");
    std::cout << buffer << "\n\r";
}


int Screen::getSizeX() {
    return window_size_x;
}
int Screen::getSizeY() {
    return window_size_y;
}