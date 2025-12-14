#include <iostream>
#include <string>

int main() {
	std::string s = " 12";
	std::cout << std::to_string(std::stoi(s)).length() << std::endl; 

	return 0;
}

