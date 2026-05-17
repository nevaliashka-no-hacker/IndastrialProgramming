#include "generate.hpp"
#include <iostream>

int main(std::string filename) {
	
	std::string code = "hello";
	generate(code, filename);


	char n;
	std::cin >> n;
	return 0;
}
