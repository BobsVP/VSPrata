#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
using std::cout;
using std::endl;

template<typename T>

class HasFriend
{
private:
	T item;
	static int st;
public:
	HasFriend(const T& i) :item(i) { st++; }
	~HasFriend() { st--; }
	friend void counts();
	friend void Reports(HasFriend<T>&);
};

template<typename T>
int HasFriend<T>::st = 0;

void counts()
{
	cout << "int count: " << HasFriend<int>::st << "; ";
	cout << "double count: " << HasFriend<double>::st << "\n";
}

void Reports(HasFriend<int>& hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

void Reports(HasFriend<double>& hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}


#endif