#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>


void calcfuel(int &n) {
	int sum = 0;
	int part = n;
	while ((part = part / 3 - 2) > 0) {
		sum += part;
	}
	n = sum;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "Need argument\n";
		return 1;
	}

	std::ifstream file;
	file.open(argv[1]);
	if (file.fail()) {
		std::cout << "Can't open file " << argv[1] << "\n";
		return 1;
	}

	std::vector<int> numbers;
	int number = 0;

	while (file >> number) {
		numbers.push_back(number);
	}

	std::for_each(numbers.begin(), numbers.end(), calcfuel);
	int result = std::accumulate(numbers.begin(), numbers.end(), 0);

	std::cout << "Result: " << result << "\n";

	return 0;
}