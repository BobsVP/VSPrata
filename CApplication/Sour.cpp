#include"Header.h"
#include<iostream>
//using std::cout;
//using std::endl;

int main()
{
	beta<double> guy(3.5, 3);
	cout << "T was set to double\n";
	guy.Show();
	cout << "V was set to T, which is double, then V was set to int\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U was set to int\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U was set to double\n";
	cout << "Done.\n";
	return 0;
}

