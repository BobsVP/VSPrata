#include"Header.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Grab<Stack> nebula;
	int ni;
	double nb;
	cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}
	while (nebula.pop(ni, nb))
	{
		cout << ni << ", " << nb << '\n';
	}
	cout << "Done.\n";
	return 0;
}

