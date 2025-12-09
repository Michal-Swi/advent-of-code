#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#define ULL unsigned long long

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

	return (p1.first <= p2.first and p1.second >= p2.first);
}

void merge_merged() {
	std::sort(merged.begin(), merged.end());

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
	for (int i = 0; i < merged.size(); i++) {
		std::cout << merged[i].second << std::endl; 
			// << ' ' << merged[i].second << std::endl;
	}
}

int main() {
	std::ifstream file("ranges");
	
	ULL left, right;
	while (file >> left and file >> right) {
		merged.push_back(std::make_pair(left, right));
	}

	for (int i = 0; i < 20000; i++) {
		merge_merged();
	}

	std::sort(merged.begin(), merged.end());

	ULL ans = 0;
	for (auto [st, nd] : merged) {
		ans += nd - st + 1;
	}

	std::cout << ans << std::endl;

	return 0;
}

