#include "SimpleServer.hpp"

namespace PROTO{
	class TestServer : public SimpleServer{
		private:
			char buffer[300000] = {0};
			int new_socket;
			void acceptor();
			void handler();
			void responder();
			int readed;
		public:
			TestServer();
			void launch();
	};
}