#include <stdio.h>
#include "ConnectingSocket.hpp"

PROTO::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long intrface) : SimpleSocket(domain, service, protocol, port, intrface)
{
	connect_to_network(get_sock(), get_address());
	test_connection(connected);
}

void PROTO::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	connected = connect(sock, (struct sockaddr *)&address, sizeof(address));
	return;
}

int PROTO :: ConnectingSocket :: get_connected(){
	return connected;
}