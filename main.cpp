#include <fstream>
#include <iostream>
void validateUserArguments(int, char **);
int main(int argc, char **argv) {
	validateUserArguments(argc, argv);

	std::ifstream inFile(argv[1]);
	std::ifstream maskFile(argv[2]);
	std::ofstream avgFile(argv[4]);
	std::ofstream medianFile(argv[5]);
	std::ofstream gaussFile(argv[6]);
	std::ofstream logFile(argv[7]);

	inFile.close();
	maskFile.close();
	avgFile.close();
	medianFile.close();
	gaussFile.close();
	logFile.close();
}

void validateUserArguments(int argc, char **argv) {
	if (argc != 8) {
		std::cout << "Your command line must include seven parameters: inFile, "
					 "maskFile, thrVal, avgFile, medianFile, gaussFile, logFile"
				  << std::endl;
		exit(1);
	}

	std::ifstream inFile(argv[1]);
	if (!inFile.is_open()) {
		std::cout << "Unable to open input file " << argv[1] << std::endl;
		exit(1);
	}

	std::ifstream maskFile(argv[2]);
	if (!maskFile.is_open()) {
		std::cout << "Unable to open mask file " << argv[2] << std::endl;
		exit(1);
	}

	if (argv[3][0] == '-') {
		std::cout << "Threshold cannot be a negative value. You entered " << argv[3] << std::endl;
		exit(1);
	}

	std::ofstream avgFile(argv[4]);
	if (!avgFile.is_open()) {
		std::cout << "Unable to open Averages file " << argv[4] << std::endl;
		exit(1);
	}

	std::ofstream medianFile(argv[5]);
	if (!medianFile.is_open()) {
		std::cout << "Unable to open Median file " << argv[5] << std::endl;
		exit(1);
	}

	std::ofstream gaussFile(argv[6]);
	if (!gaussFile.is_open()) {
		std::cout << "Unable to open Gaussians file " << argv[6] << std::endl;
		exit(1);
	}

	std::ofstream logFile(argv[7]);
	if (!logFile.is_open()) {
		std::cout << "Unable to open Log file " << argv[7] << std::endl;
		exit(1);
	}
}
