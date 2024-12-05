#include "ListeningSocket.hpp"
#include <winsock2.h>
#define GETSOCKETERRNO() (WSAGetLastError())
using namespace std;

int main()
{
	std::cout << "Starting..." << std::endl;
	std::cout << "Binding Socket..." << std::endl;
	PROTO::BindingSocket bs = PROTO::BindingSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);
	std::cout << "Listening Socket..." << std::endl;
	PROTO::ListeningSocket ls = PROTO::ListeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
	WSACleanup();
	return 0;
}