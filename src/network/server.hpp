#ifndef BS_SERVER_H
#define BS_SERVER_H

class Server
{
	static Server* _self;
private:

	int m_socket;

	Server();
public:
	Server(const Server& obj) = delete;

	static Server* get();
	static int Initialization();

	int start();
};

#endif