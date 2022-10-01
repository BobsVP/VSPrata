//#include"Header.h"
#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		std::cerr << "Too few command line options found. Execution terminated." << std::endl;
		std::cin.get(); 
		exit(EXIT_FAILURE);
	}
	std::ifstream File1(argv[1]);
	if (!File1.is_open())
	{
		std::cerr << "\nCould not open input file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	std::ofstream File2(argv[2]);
	if (!File2.is_open())
	{
		std::cerr << "\nCould not open output file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	char ch;
	while (File1.get(ch))
	{
		File2 << ch;
	}
	File1.close();
	File2.close();
	return 0;
}

