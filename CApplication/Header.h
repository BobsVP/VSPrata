#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
#include<string>

template<typename T1, typename T2>

class Pairs
{
public:
	T1& first();
	T2& second();
	T1 first() const { return a;}
	T2& second() const { return b; }
	Pairs (const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pairs (){}
private:
	T1 a;
	T2 b;
};

template<typename T1, typename T2>
T1& Pairs<T1, T2>::first()
{
	return a;
}
template<typename T1, typename T2>
T2& Pairs<T1, T2>::second()
{
	return b;
}

#endif