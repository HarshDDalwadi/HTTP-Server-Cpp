#include <stdio.h>
#ifndef SIMPLE_SOCKET_HPP
#define SIMPLE_SOCKET_HPP
#include "SimpleSocket.hpp"
#endif 

namespace PROTO
{
	class ConnectingSocket : public SimpleSocket
	{
	private:
		int connected;

	public:
		// Constructor
		ConnectingSocket(int domain, int service, int protocol, int port, u_long intrface);

		// Virtual function from parent
		void connect_to_network(int sock, struct sockaddr_in address);
		int get_connected();
	};
}