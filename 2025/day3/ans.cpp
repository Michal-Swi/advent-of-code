#include <fstream>
#include <iostream>

int find_largest_num(const std::string &s) {
	int largest = -1;

	for (int i = 0; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			const int tmp = int(s[i] - '0') * 10 + int(s[j] - '0');
			if (tmp > largest) {
				largest = tmp;
			}
		}
	}

	return largest;
}

int main() {
	/*
	std::cout << find_largest_num("987654321111111") << std::endl;
	std::cout << find_largest_num("811111111111119") << std::endl;
	std::cout << find_largest_num("234234234234278") << std::endl;
	std::cout << find_largest_num("818181911112111") << std::endl;
	return 0;
	*/

	std::ifstream file("input");

	int ans = 0;

	std::string s; 
	while (file >> s) {
		ans += find_largest_num(s);					
	}

	std::cout << ans << std::endl;

	return 0;
}

