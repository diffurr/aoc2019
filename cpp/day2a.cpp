#include <fstream>
#include <iostream>
#include <vector>

void computer(std::vector<int> &program)
{
	size_t ip = 0;
	while (ip < program.size()) {
		switch (program[ip]) {
		case 1:
			program[program[ip + 3]] = program[program[ip + 1]] + program[program[ip + 2]];
			break;
		case 2:
			program[program[ip + 3]] = program[program[ip + 1]] * program[program[ip + 2]];
			break;
		case 99:
			return;
		default:
			std::cerr << "Incorrect program?!\n";
			exit(1);
		}
		ip += 4;
	}
	std::cerr << "Incorect program?!\n";
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Need input file\n";
		return 1;
	}

	std::ifstream file;
	file.open(argv[1]);
	if (file.fail()) {
		std::cerr << "Can't open file " << argv[1] << "\n";
		return 1;
	}

	std::vector<int> program;

	int num;
	while (file) {
		file >> num;
		file.get();
		program.push_back(num);
	}
	
	program[1] = 12;
	program[2] = 2;
	computer(program);
	std::cout << "Result: " << program[0] << "\n";
	return 0;
}