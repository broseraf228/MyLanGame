#include "server.hpp"

#include <iostream>

Server* Server::_self = nullptr;

Server* Server::get() {
	if (_self == NULL)
		throw("screen called without initialising");
	return _self;
}

Server::Server()
{
	m_socket = 0;
}

int Server::Initialization()
{
	_self = new Server();

	return 0;
}

int Server::start()
{
	return 0;
}