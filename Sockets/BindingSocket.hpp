#include <stdio.h>
#ifndef SIMPLE_SOCKET_HPP
#define SIMPLE_SOCKET_HPP
#include "SimpleSocket.hpp"
#endif 

namespace PROTO
{
	class BindingSocket : public SimpleSocket
	{
	private:
		int binding;
		// Virtual function from parent to establish binding
		void connect_to_network(int sock, struct sockaddr_in address);

	public:
		//Constructor
		BindingSocket(int domain, int service, int protocol, int port, u_long intrface);
		int get_binding();
	};
}