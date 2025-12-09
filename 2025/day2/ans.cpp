#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

#define ULL unsigned long long

std::vector<int> get_divisors(const ULL &n) {
	std::vector<int> divisors;

	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
		}
	}

	return divisors;
}

std::string get_substr(std::string &s, int &n) {
	std::string str = "";
	for (int i = 0; i < n; i++) {
		str += s[i];
	}

	return str;
}

bool invalid_num(const ULL &n) {
	std::string s = std::to_string(n); 
	auto lens = get_divisors(s.length());

	for (int i = 0; i < lens.size(); i++) {
		auto str = get_substr(s, lens.at(i));
		int j = lens.at(i), k = 0;

		bool flag = true;
		while (j < s.length()) {
			if (s[j] != str[k]) {
				flag = false;
				break;
			}

			j++;
			k++;
		
			if (k >= lens.at(i)) {
				k = 0;
			}
		}

		if (flag) {
			return true;
		}
	}

	return false;
}

ULL invalid_amount(const ULL &n, const ULL &n1) {
	ULL ans = 0;

	for (ULL i = n; i <= n1; i++) {
		if (!invalid_num(i)) {
			continue;
		}

		ans += i;
	}

	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	
	/*
	std::cout << invalid_amount(11, 22) << std::endl;
	std::cout << invalid_amount(95, 115) << std::endl;
	std::cout << invalid_amount(998, 1012) << std::endl;
	std::cout << invalid_amount(1188511880, 1188511890) << std::endl;
	std::cout << invalid_amount(222220, 222224) << std::endl;
	std::cout << invalid_amount(1698522, 1698528) << std::endl;
	std::cout << invalid_amount(446443, 446449) << std::endl;
	std::cout << invalid_amount(38593856, 38593862) << std::endl;
	std::cout << invalid_amount(565653, 565659) << std::endl;
	std::cout << invalid_amount(824824821, 824824827) << std::endl;
	std::cout << invalid_amount(2121212118, 2121212124) << std::endl;
	return 0;
	*/
		
	std::ifstream file("in");
	ULL ans = 0;

	ULL n, n1;
	while (file >> n and file >> n1) {
		ans += invalid_amount(n, n1);
	}

	std::cout << ans << std::endl;

	return 0;
}

