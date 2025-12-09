#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define ULL unsigned long long 

std::vector<int> get_substr(const std::string &s, int begin, int nums_left) {
	std::vector<int> substr;

	for (; begin < s.length() - nums_left; begin++) {
		substr.push_back(s[begin] - '0');	
	}

	return substr;
}

std::pair<int, int> find_greatest(std::vector<int> v) {
	std::pair<int, int> p_max = {-1, -1};

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > p_max.first) { 
			p_max.first = v[i];
			p_max.second = i;
		}
	}

	return p_max;
}

ULL find_largest_num(const std::string &s) {
	std::string largest = "";
	
	int begin = 0;
	for (int i = 0; i < 12; i++) {
		auto p = find_greatest(get_substr(s, begin, 11 - i));

		largest += (p.first + '0');	
		begin += p.second + 1;
	}

	return std::stoull(largest);
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

	ULL ans = 0;

	std::string s;
	while (file >> s) {
		ans += find_largest_num(s);
	}

	std::cout << ans << std::endl;

	return 0;
}

