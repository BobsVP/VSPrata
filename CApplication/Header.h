#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class ManyFriendT
{
private:
	T item;
public:
	ManyFriendT(const T& i) :item(i) { }
	template<typename C, typename D> friend void show2(C&, D&);
};

template<typename C, typename D> void show2(C& c, D& d)
{
	cout << c.item << ", " << d.item << endl;
}


#endif