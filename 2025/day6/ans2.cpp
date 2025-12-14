#include <algorithm>
#include <array>
#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define ULL unsigned long long

struct Column {
	std::string num;
	size_t relative_pos;
};

std::vector<Column> parse_string(const std::string &s) {
	std::vector<Column> parsed;
		
	bool was_digit = false, first = true;
	std::string str = "";
	Column col;

	for (size_t i = 0; i < s.length(); i++) {
		if (std::isdigit(s[i]))	{
			was_digit = true;
			str += s.at(i);

			if (first) {
				col.relative_pos = i;
				first = false;
			}
		}

		if (s.at(i) == ' ' and was_digit) {
			was_digit = false;
			first = true;
			
			col.num = str;
			parsed.push_back(col);
			str = "";
		} else if (s.at(i) == ' ' and !was_digit) {
			str += s.at(i);
		}
	}

	if (str.empty()) {
		return parsed;
	}

	col.num = str;
	parsed.push_back(col);
	
	return parsed;
}

ULL count(char &op, const std::vector<Column> &cols) {
	ULL ans = 0;

	std::map<size_t, std::string> mp;
	for (size_t i = 0; i < cols.size(); i++) {

		size_t digit_i = 0;
		for (size_t j = 0; j < cols.at(i).num.length(); j++) {
			if (std::isdigit(cols.at(i).num.at(j))) {
				mp[cols.at(i).relative_pos + digit_i] += cols.at(i).num.at(j);
				digit_i++;
			}
		}
	}

	for (auto [key, value] : mp) {
		ULL val = std::stoull(value);
		if (ans == 0) {
			ans = val;
			continue;
		}

		if (op == '*') {
			ans *= val;
		} else if (op == '+') {
			ans += val;
		}
	}

	return ans;
}

int main() {
	std::ifstream file("./nums");

	std::vector<std::vector<Column>> vc;
	std::string s;
	for (size_t i = 0; i < 4; i++) {
		std::getline(file, s); 
		vc.push_back(parse_string(s));
	}

	std::ifstream operations("./operations");
	std::vector<char> ops;

	char ch;
	while (operations >> ch) {
		ops.push_back(ch);
	}

	ULL ans = 0;
	for (size_t i = 0; i < ops.size(); i++) {
		ans += count(ops.at(i), {
			vc.at(0).at(i), vc.at(1).at(i),
			vc.at(2).at(i), vc.at(3).at(i)
		});
	}

	std::cout << ans << std::endl;

	return 0;
}

