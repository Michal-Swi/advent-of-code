#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

/*			WARNING!!!!
 *	THIS FILE CONTAINS GENIUENLY
 *	SOME OF THE WORST CODE I HAVE 
 *	EVER EVER EVER EVER WRITTEN
 */ 

#define ULL unsigned long long

struct Column {
	std::vector<ULL> nums;
	char operation;
};

std::vector<ULL> convert_vector(const std::vector<std::string> &v) {
	int max_len = -1;
	
	for (const auto &s : v) {
		max_len = std::max(max_len, static_cast<int>(s.length()));
	}
	
	std::vector<ULL> vc;
	while (max_len > 0) {
		ULL tmp = 0;

		// std::cout << it << std::endl;
		for (const auto &s : v) {
			if (s.length() == 0) {
				continue;
			}

			if (s.length() <= max_len - 1 or s.at(max_len - 1) == ' ') {
				continue;
			}
			
			tmp = tmp * 10 + (s.at(max_len - 1) - '0');
			// std::cout << s << ' ' << s.at(max_len - 1) << std::endl;
		}

		if (tmp != 0) {
			vc.push_back(tmp);
		}

		max_len--;
	}

	return vc;
}

std::vector<std::string> parse_line(const std::string &line) {
	std::vector<std::string> parsed;

	std::string s = "";
	bool was_digit = false;
	for (int i = 0; i < line.length(); i++) {
		if (std::isdigit(line[i])) {
			s += line[i];	
			was_digit = true;
			continue;
		}

		// line[i] has to be a whitespace
		if (was_digit) {
			parsed.push_back(s);
			s = "";
			was_digit = false;
		} else {
			s += line[i];
		}
	}

	parsed.push_back(s);

	return parsed;
}

std::string delete_n_leading_spaces(const std::string &s, const int n) {
	std::string str = "";
	
	int i = 0;
	for (; i < n; i++) {
		if (s.at(i) != ' ') {
			break;
		}
	}

	for (; i < s.length(); i++) {
		str += s.at(i);
	}	

	return str;
}

std::vector<std::string> align_nums(const std::vector<std::string> &v) {
	std::vector<std::string> aligned;
	
	int max_num_len = -1;
	for (auto s : v) {
		max_num_len = std::max(max_num_len, 
			static_cast<int>(std::to_string(std::stoi(s)).length()));
	}

	for (const auto &s : v) {
		aligned.push_back(delete_n_leading_spaces(s, s.length() - max_num_len));
	}

	return aligned;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::ifstream nums_file("./t_in");
	std::ifstream operations("./t_op");

	std::vector<std::vector<std::string>> nums;

	std::string s;	
	int lines = 4;
	while (lines--) {
		std::getline(nums_file, s);
		if (s.length() == 0) {
			continue;
		}

		nums.push_back(parse_line(s));
	}

	std::vector<char> ops;
	char op;
	while (operations >> op) {
		ops.push_back(op);
	}

	std::vector<std::vector<std::string>> intermediate;
	for (int i = 0; i < nums.at(0).size(); i++) {
		std::vector<std::string> tmp;
			
		for (int j = 0; j < 4; j++) {
			tmp.push_back(nums.at(j).at(i));
		}

		intermediate.push_back(tmp);
	}	

	// /*
	for (int i = 0; i < intermediate.size(); i++) {
		for (int j = 0; j < intermediate.at(i).size(); j++) {
			std::cout << intermediate.at(i).at(j) << std::endl;
		}

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
	// */

	std::vector<Column> cols;
	for (int i = 0; i < intermediate.size(); i++) {
		Column tmp;
		tmp.nums = convert_vector(intermediate.at(i));
		tmp.operation = ops.at(i); 
		cols.push_back(tmp);
	}
	
	/*
	for (auto col : cols) {
		for (auto n : col.nums) {
			std::cout << n << ' ';
		}
		std::cout << std::endl;
	}
	*/

	ULL ans = 0;		
	for (auto col : cols) {
		ULL t_ans = col.nums.at(0);

		for (int i = 1; i < col.nums.size(); i++) {
			if (col.operation == '+') {
				t_ans += col.nums.at(i);
			} else {
				t_ans *= col.nums.at(i);
			}
		}

		// std::cout << t_ans << std::endl;
		ans += t_ans;
	}
	
	std::cout << ans << std::endl;

	return 0;
}

