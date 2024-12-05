#include<unistd.h>
#include <WS2tcpip.h>
#include "../hdelibc-networking.hpp"

namespace PROTO
{
	class SimpleServer
	{
	private:
		ListeningSocket *socket;
		virtual void acceptor() = 0;
		virtual void handler() = 0;
		virtual void responder() = 0;
	public:
		SimpleServer(int domain, int service, int protocol, int port, u_long intrface, int bklog);

		//Infinite loop in the child class which will call acceptor, handler and responder infinitely
		virtual void launch() = 0;
		ListeningSocket* get_socket();
	};
}