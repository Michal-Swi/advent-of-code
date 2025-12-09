#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using Grid = std::vector<std::string>;
Grid grid;
Grid t_grid;

bool condition(int i, int j) {
	int neighbours = 0;

	if (i >= grid.size() - 1) goto i_equals_max;

	if (j < grid.at(i + 1).length() - 1) {
		neighbours += grid.at(i + 1).at(j + 1) == '@';
	}
	
	if (j > 0) {
		neighbours += grid.at(i + 1).at(j - 1) == '@';
	}
	neighbours += grid.at(i + 1).at(j) == '@';

	i_equals_max:
	if (i == 0) goto i_equals_zero;

	if (j < grid.at(i - 1).length() - 1) {
		neighbours += grid.at(i - 1).at(j + 1) == '@';
	}

	if (j > 0) {
		neighbours += grid.at(i - 1).at(j - 1) == '@';
	}
	neighbours += grid.at(i - 1).at(j) == '@';
	
	i_equals_zero:
	if (j < grid.at(i).length() - 1) {
		neighbours += grid.at(i).at(j + 1) == '@';
	}

	if (j > 0) {
		neighbours += grid.at(i).at(j - 1) == '@';
	}

	// std::cout << neighbours << ' ' << i << ' ' << j << std::endl;

	return neighbours < 4;
}

int count_rolls() {
	int rolls = 0;
	t_grid = grid;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.at(i).length(); j++) {
			if (grid.at(i).at(j) != '@') {
				continue;
			}

			if (condition(i, j)) {
				rolls++; 
				t_grid.at(i).at(j) = '.';
			}
		}
	}

	grid = t_grid;

	return rolls;
}

int main() {
	std::ifstream file("input");

	std::string s;
	while (file >> s) {
		grid.push_back(s);
	}

	int ans = 0;
	while (true) {
		const int tmp = count_rolls();
		ans += tmp;

		// std::cout << tmp << std::endl;

		if (tmp == 0) {
			break;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}

