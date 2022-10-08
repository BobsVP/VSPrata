//#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
#include<set>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char * argv[])
{
	std::ifstream FileInput1("mat.dat");
	if (!FileInput1.is_open())
	{
		std::cerr << "\nCould not open input file ""mat.dat"". Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	std::ifstream FileInput2("pat.dat");
	if (!FileInput2.is_open())
	{
		std::cerr << "\nCould not open intput file#2. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	std::ofstream FileOutput("matnpat.dat");
	if (!FileOutput.is_open())
	{
		std::cerr << "\nCould not open output file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	std::set<std::string> MatList;
	std::string str;
	cout << "\t\tMat's list:" << endl;
	while (!FileInput1.eof())
	{
		if (getline(FileInput1, str))
			MatList.insert(str);
	}
	for (auto const &i : MatList)
		cout << i << endl;
	std::set<std::string> PatList;
	cout << "\t\tPat's list:" << endl;
	while (!FileInput2.eof())
	{
		if (getline(FileInput2, str))
			PatList.insert(str);
	}
	for (auto const &i : PatList)
		cout << i << endl;
	MatList.insert(PatList.begin(), PatList.end());
	//cout << "\t\tCombined list" << endl;
	for (auto const& i : MatList)
		FileOutput << i << endl;
	FileInput1.close();
	FileInput2.close();
	FileOutput.close();
	return 0;
}

