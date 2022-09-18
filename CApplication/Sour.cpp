//#include"Header.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
const int Limit = 255;

int main()
{
	char input[Limit];
	cout << "Enter a string to count the number of characters:" << endl;
	cin.get(input, Limit, '$');
	int count = 0;
	for (size_t i = 0; i < Limit; ++i)
	{
		if (input[i] != '\0')
			count++;
		else
			break;
	}
	char ch;
	cin.get(ch);
	cout << "You entered the " << count << " of characters" << endl << ch;
	return 0;
}

