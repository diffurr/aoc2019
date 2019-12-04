#include <fstream>
#include <iostream>
#include <vector>

void computer(std::vector<int>& program)
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

int modifycompute(std::vector<int> program, int noun, int verb)
{
	program[1] = noun;
	program[2] = verb;
	computer(program);
	return program[0];
}

int main(int argc, char** argv)
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

	for (int noun = 0; noun <= 99; noun++) {
		for (int verb = 0; verb <= 99; verb++) {
			if (19690720 == modifycompute(program, noun, verb)) {
				std::cout << "Result: " << 100 * noun + verb << "\n";
				return 0;
			}
		}
	}

	return 0;
}