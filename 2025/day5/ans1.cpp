#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#define ULL unsigned long long

std::vector<std::pair<ULL, ULL>> vc;
std::vector<std::pair<ULL, ULL>> merged;

std::pair<ULL, ULL> merge(std::pair<ULL, ULL> range1, std::pair<ULL, ULL> range2) {
	range1.second = std::max(range1.second, range2.second);
	range1.first = std::min(range1.first, range2.first);
	return range1;
}

bool con(std::pair<ULL, ULL> p1, std::pair<ULL, ULL> p2) {
	if (p1.first > p2.first) {
		std::swap(p1, p2);
	}

	return p1.first < p2.first and p1.second > p2.first;
}

void merge_merged() {
	for (int i = 0; i < merged.size(); i++) {
		auto p = merged[i];
		merged.erase(merged.begin() + i, merged.begin() + i + 1);

		bool merged_flag = false;
		for (int j = 0; j < merged.size(); j++) {
			if (i == j) {
				continue;
			}

			if (con(p, merged[j])) {
				merged[j] = merge(p, merged[j]);
				merged_flag = true;
				break;
			}
		}

		if (!merged_flag) {
			merged.push_back(p);
		}
	}
}

void print_merged() {
	for (auto &[st, nd] : merged) {
		std::cout << st << ' ' << nd << std::endl;
	}

	std::cout << std::endl;
}

int main() {
	/*
	auto p = (merge({10, 14}, {16, 20}));
	std::cout << p.first << ' ' << p.second << std::endl;
	return 0;
	*/

	std::ifstream file("ranges");

	ULL left, right;
	while (file >> left and file >> right) {
		vc.push_back(std::make_pair(left, right));
	}

	std::vector<std::pair<ULL, ULL>> covered;
	for (int i = 0; i < vc.size(); i++) {
			
	}
	
	// std::sort(vc.begin(), vc.end(), std::less<ULL>());
	
	for (int i = 0; i < vc.size(); i++) {
		bool merged_flag = false;
		for (int j = 0; j < merged.size(); j++) {
			if (con(vc[i], vc[j])) {
				merged[j] = merge(merged[j], vc[i]);
				merged_flag = true;
				break;
			} 
		}

		if (!merged_flag) {
			merged.push_back(vc[i]);
		}
	}

	// print_merged();

	int prev = -1;
	while (prev != merged.size()) {
		prev = merged.size();
		merge_merged();
		// print_merged();

		if (prev == merged.size()) {
			break;
		}	
	}

	ULL ans = 0;
	for (auto [st, nd] : merged) {
		ans += nd - st + 1; 
	}

	std::cout << ans << std::endl;

	return 0;
}

