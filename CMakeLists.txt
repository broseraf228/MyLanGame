cmake_minimum_required(VERSION 3.16)
project(MyLanGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable( ${PROJECT_NAME}
	src/main.cpp
	src/screen.hpp
	src/screen.cpp
	src/network/server.hpp
	src/network/server.cpp
	src/game/Game.hpp
	src/game/Game.cpp
	src/game/chess_piece.hpp
	src/game/chess_piece.cpp
	src/Events.hpp
	src/Events.cpp
	)