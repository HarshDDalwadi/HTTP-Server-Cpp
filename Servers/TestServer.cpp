#include "TestServer.hpp"


PROTO::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10){
	launch();
}

void PROTO ::TestServer ::acceptor()
{
	struct sockaddr_in address = get_socket()->get_address();
	int addrlen = sizeof(address);
	new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
	read(new_socket, buffer, 300000);
}

void PROTO::TestServer::handler()
{
	std::cout<<"SOCKET CREATED : "<<new_socket<<std::endl;
	std::cout << "THIS IS BUFFER : "<< buffer << std::endl;
}

void PROTO::TestServer::responder(){
	char *hello = "HELLO FROM THE SERVER";
	write(new_socket, hello, strlen(hello));
}

void PROTO::TestServer::launch(){
	while(true){
		std::cout<<"====WAITING===="<<std::endl;
		acceptor();
		handler();
		responder();
		std::cout<<"====DONE===="<<std::endl;
		close(new_socket);
	}
}