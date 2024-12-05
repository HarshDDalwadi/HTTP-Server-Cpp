#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <stdlib.h>

namespace PROTO
{
	class SimpleSocket
	{
	private:
		int sock;
		struct sockaddr_in address;

	public:
		SimpleSocket(int domain, int service, int protocol, int port, u_long intrface); // domain of your socket

		// Virtual function to connect to a network
		virtual void connect_to_network(int sock, struct sockaddr_in address) = 0;

		// Function to test sockets and connections
		void test_connection(int);
		// Getter functions
		struct sockaddr_in get_address();
		int get_sock();
		// Setter functions
	};
}