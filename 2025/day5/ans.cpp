#include <charconv>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>

#define ULL unsigned long long

std::vector<std::pair<ULL, ULL>> v;

bool valid(ULL &n) {
	for (int i = 0; i < v.size(); i++) {
		if (n >= v.at(i).first and n <= v.at(i).second) {
			return true;
		}
	}

	return false;
}

int main() {
	std::ios_base::sync_with_stdio(0);

	std::ifstream ranges("ranges");
	std::ifstream ids("ids");
	
	ULL left, right;
	while (ranges >> left and ranges >> right) {
		v.push_back(std::make_pair(left, right));
	}

	ULL ans = 0;

	ULL n;
	while (ids >> n) {
		ans += valid(n); 
	}

	std::cout << ans << std::endl;

	return 0;
}

