//#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char * argv[])
{
	if (argc < 4)
	{
		std::cerr << "Too few command line options found. Execution terminated." << std::endl;
		std::cin.get(); 
		exit(EXIT_FAILURE);
	}
	std::ifstream FileInput1(argv[1]);
	if (!FileInput1.is_open())
	{
		std::cerr << "\nCould not open input file#1. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	std::ifstream FileInput2(argv[2]);
	if (!FileInput2.is_open())
	{
		std::cerr << "\nCould not open intput file#2. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	std::ofstream FileOutput(argv[3]);
	if (!FileOutput.is_open())
	{
		std::cerr << "\nCould not open output file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	std::string str;
	while (!FileInput1.eof() || !FileInput2.eof())
	{
		if (getline(FileInput1, str))
			FileOutput << str;
		if (!FileInput1.eof() && !FileInput2.eof())
			FileOutput << " ";
		if (getline(FileInput2, str))
			FileOutput << str;
		if (!FileInput1.eof() || !FileInput2.eof())
			FileOutput << endl;
	}
	FileInput1.close();
	FileInput2.close();
	FileOutput.close();
	return 0;
}

