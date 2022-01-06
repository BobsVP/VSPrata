#include"Header.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	ManyFriendT<int> hfi1(10);
	ManyFriendT<int> hfi2(20);
	ManyFriendT<double> hfdb(10.5);
	cout << "hfi1, hfi2:\n";
	show2(hfi1, hfi2);
	cout << "hfdb, hfi2:\n";
	show2(hfdb, hfi2);
	return 0;
}

