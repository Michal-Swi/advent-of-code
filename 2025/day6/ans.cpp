#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

#define ULL unsigned long long

struct Column {
	std::vector<ULL> nums;
	char operation;
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::ifstream nums("nums");
	std::ifstream operations("operations");

	std::vector<ULL> ns;

	ULL n;	
	while (nums >> n) {
		ns.push_back(n);
	}
	
	std::vector<char> ops;

	char op;
	while (operations >> op) {
		ops.push_back(op);
	}

	std::vector<Column> cols;
	for (int i = 0; i < ops.size(); i++) {
		Column tmp;

		for (int j = i; j < ns.size(); j += ops.size()) {
			tmp.nums.push_back(ns.at(j));
		}

		tmp.operation = ops.at(i);
		cols.push_back(tmp);
	}

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

