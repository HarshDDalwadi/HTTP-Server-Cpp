#include <stdio.h>
#include "ListeningSocket.hpp"

// Constructor

PROTO::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long intrface, int bklog) : BindingSocket(domain, service, protocol, port, intrface)
{
	backlog = bklog;
	start_listening();
	test_connection(listening);
}

void PROTO::ListeningSocket::start_listening()
{
	listening = listen(get_sock(), backlog);
}

//GETTERS
int PROTO :: ListeningSocket::get_listening(){
	return listening;
}

int PROTO :: ListeningSocket :: get_backlog(){
	return backlog;
}