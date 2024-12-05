#include "SimpleServer.hpp"


PROTO :: SimpleServer :: SimpleServer(int domain, int service, int protocol, int port, u_long intrface, int bklog){
	socket = new ListeningSocket(domain, service, protocol, port, intrface, bklog);
}

PROTO :: ListeningSocket* PROTO :: SimpleServer :: get_socket(){
	return socket;
}