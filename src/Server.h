/*
 * Server.h
 *
 *  Created on: 26.06.2015
 *      Author: karsten
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <vector>
#include "asio.hpp"

namespace rcurse_server {

class Server {
private:
	void listen_thread();
	void receive_thread(std::shared_ptr<asio::ip::tcp::socket> sock);

	std::vector<std::shared_ptr<std::thread>> receivers;
	std::thread listener;
	asio::io_service io;
	unsigned short port;
public:
	Server(unsigned short _port);
	virtual ~Server();

	void run();
};

} /* namespace rcurse_server */

#endif /* SERVER_H_ */
