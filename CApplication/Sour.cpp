//#include"Header.h"
#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char * argv[])
{
	std::ofstream Fout(argv[1]);
	cout << "Enter a string to write in file:" << endl;
	char ch;
	while (cin.get(ch))
	{
		Fout << ch;
	}
	Fout.close();
	return 0;
}

