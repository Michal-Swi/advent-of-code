#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

struct Instruction {
	int n;
	char direction;
};

Instruction convert(std::string s) {
	Instruction instruction;
	
	instruction.direction = s.at(0);
	
	std::string rest;
	for (int i = 1; i < s.length(); i++) {
		rest += s[i];
	}	

	instruction.n = std::stoi(rest);

	return instruction;
}

int rotate(Instruction instruction, int &n) {
	int zeros = 0;	
	
	for (int i = 0; i < instruction.n; i++) {
		if (instruction.direction == 'R') {
			n++;
		} else if (instruction.direction == 'L') {
			n--;
		}

		if (n >= 100) {
			n = 0;
		}
		
		if (n < 0) {
			n = 99;
		}

		if (n == 0) {
			zeros++;
		}
	}

	return zeros;
}

int main() {
	std::ifstream file("input");
	
	int ans = 0;
	int n = 50;

	// int i = 0;

	std::string s;
	while (file >> s) {
		auto instruction = convert(s);
		ans += rotate(instruction, n);
		/*
		std::cout << "Dial is at: " << n << "\nCurrent ans: " << ans 
				  << "\nInstruction: " << instruction.direction << ' ' 
				  << instruction.n << std::endl << std::endl;

		if (i > 300) {
			break;
		}

		i++;
		*/
	}

	std::cout << ans << std::endl;

	return 0;
}

