#include <iostream>
#include <vector>

int main() {
	std::vector<int> vc = {1, 4, 5, 6};

	vc.erase(vc.begin() + 2, vc.begin() + 3);

	for (auto n : vc) {
		std::cout << n << ' ';
	}

	return 0;
}

