/*
 * main.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: wysiwyng
 */

#include <iostream>
#include <sstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	int port = 0;
	std::string inp;

	if(argc == 1) {
		std::cout << "port: ";
		std::cin >> port;
	}
	else if(argc == 2) {
		port = atoi(argv[1]);
	}
	std::cout << "starting server on port " << port << std::endl;

}
