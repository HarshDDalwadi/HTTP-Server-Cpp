#include "SimpleSocket.hpp"

// Default Constructor

PROTO::SimpleSocket ::SimpleSocket(int domain, int service, int protocol, int port, u_long intrface)
{

	// Define address structure
	WSADATA wsaData;
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(intrface);
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		std::cerr << "WSAStartup failed with error: " << WSAGetLastError() << std::endl;
		exit(EXIT_FAILURE);
	}

	// Establish Socket
	sock = socket(domain, service, protocol);
	// Test Socket
	test_connection(sock);
}

// Test connection virtual function

void PROTO::SimpleSocket::test_connection(int item_to_test)
{
	// Confirm that the socket or connection has been properly established
	if (item_to_test < 0)
	{
		perror("Failed to connect...");
		exit(EXIT_FAILURE);
	}
}

// Getter functions
struct sockaddr_in PROTO::SimpleSocket::get_address()
{
	return address;
}

int PROTO::SimpleSocket::get_sock()
{
	return sock;
}