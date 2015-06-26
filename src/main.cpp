/*
 * main.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: wysiwyng
 */

#include <iostream>
#include <sstream>
#include <cstdlib>

#include <Server.h>

int main(int argc, char* argv[]) {
	int port = 0;
	std::string inp;
	std::stringstream inps;

	if(argc == 1) {
		std::cout << "port: ";
		getline(std::cin, inp);
		inps.str(inp);
	}
	else if(argc == 2) {
		inps.str(argv[1]);
	}

	inps >> port;
	std::cout << "starting server on port " << port << std::endl;

	while(1) {
		std::cout << "> ";
		getline(std::cin, inp);

		if(inp == "exit" || inp == "quit" || inp == "stop") {
			break;
		}
	}
}
