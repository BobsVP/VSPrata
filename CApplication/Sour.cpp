#include"Header.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "No objects declarated: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declarated: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declarated: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declarated: ";
	counts();
	Reports(hfi1);
	Reports(hfi2);
	Reports(hfdb);
	return 0;
}

