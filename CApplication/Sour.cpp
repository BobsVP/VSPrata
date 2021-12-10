#include"Header.h"
#include<iostream>
#include<cstring>

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	Worker* lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ++ct)
	{
		char choise;
		cout << "Enter the employee category:\n"
			<< "w:waiter, s:singer, t:singing waiter, q:quit\n";
		cin >> choise;
		while (strchr("wstq", choise) == NULL)
		{
			cout << "Please enter a w, s, t or q: ";
			cin >> choise;
		}
		if (choise == 'q')
			break;
		switch (choise)
		{
		case 'w':lolas[ct] = new Waiter;
			break;
		case 's':lolas[ct] = new Singer;
			break;
		case 't':lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; ++i)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; ++i)
		delete lolas[i];
	cout << "Bye!\n";
	return 0;
}

