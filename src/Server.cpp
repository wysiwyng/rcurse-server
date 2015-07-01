/*
 * Server.cpp
 *
 *  Created on: 26.06.2015
 *      Author: karsten
 */

#include <cstdlib>
#include <iostream>
#include <functional>
#include <thread>
#include "Server.h"

namespace rcurse_server {

Server::Server(unsigned short _port) :
port(_port)
{
	// TODO Auto-generated constructor stub

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

void Server::run() {
	try {
		listener = std::thread(std::bind(&Server::listen_thread, this));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Server::listen_thread() {
	try {
		using asio::ip::tcp;
		tcp::acceptor a(io, tcp::endpoint(tcp::v4(), port));
		while(1) {
			std::shared_ptr<tcp::socket> sock(new tcp::socket(io));
			a.accept(*sock);
			std::shared_ptr<std::thread> receiver(new std::thread(std::bind(&Server::receive_thread, this, sock)));
			receivers.push_back(receiver);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Server::receive_thread(std::shared_ptr<asio::ip::tcp::socket> sock) {

}

} /* namespace rcurse_server */
