#include <stdio.h>
#include "BindingSocket.hpp"
#include <ws2tcpip.h>

// Constructor

PROTO::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long intrface) : SimpleSocket(domain, service, protocol, port, intrface)
{
	BOOL optVal = TRUE;
	if (setsockopt(get_sock(), SOL_SOCKET, SO_REUSEADDR, (char *)&optVal, sizeof(optVal)) == SOCKET_ERROR)
	{
		std::cerr << "setsockopt failed with error: " << WSAGetLastError() << std::endl;
		WSACleanup();
		exit(EXIT_FAILURE);
	}
	connect_to_network(get_sock(), get_address());
	test_connection(binding);
}

// Defination of connect_to_network virtual function
void PROTO::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
	return;
}