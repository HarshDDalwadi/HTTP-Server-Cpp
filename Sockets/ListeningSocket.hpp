#include <stdio.h>
#ifndef BINDING_SOCKET_HPP
#define BINDING_SOCKET_HPP
#include "BindingSocket.hpp"
#endif 

namespace PROTO
{
	class ListeningSocket : public BindingSocket
	{
	private:
		int backlog;
		int listening;
		void start_listening();

	public:
		ListeningSocket(int domain, int service, int protocol, int port, u_long intrface, int bklog);
		int get_listening();
		int get_backlog();
	};
}