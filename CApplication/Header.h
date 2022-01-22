#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
#include<string>
#include<valarray>
using std::cout;
using std::endl;

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1& first();
    T2& second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1& aval, const T2& bval) : a(aval), b(bval) { }
    Pair() {}
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
    return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
    return b;
}

using ArraiInt = std::valarray<int>;
using PairArray = Pair<ArraiInt, ArraiInt>;

class Wine :private PairArray, std::string
{
private:
    int ColYear;
public:
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);
    ~Wine() { }
    void GetBottles();
	void Show() const;
    std::string Label() { return (const std::string&)(*this); }
	int const sum();
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) :
    std::string(l), ColYear(y), PairArray(ArraiInt(y), ArraiInt(y))
{
   for (int i = 0; i < ColYear; ++i)
    {
       PairArray::first()[i] = yr[i];
       PairArray::second()[i] = bot[i];
   }

}
Wine::Wine(const char* l, int y):std::string(l), ColYear(y), PairArray(ArraiInt(y), ArraiInt(y))
{
}
void Wine::GetBottles()
{
    for (int i = 0; i < ColYear; ++i)
    {
        std::cout << "Enter year: ";
        int ttmp;
        std::cin >> ttmp;
        PairArray::first()[i] = ttmp;
        std::cout << "Enter bottles for that year: ";
        std::cin >> ttmp;
        PairArray::second()[i] = ttmp;
    }
}
void Wine::Show() const
{
    std::cout << "Wine: " << (const std::string&)(*this) << endl;
    std::cout << "\tYear" << "\tBottles" << endl;;
    for (int i = 0; i < ColYear; ++i)
    {
        std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << endl;;
    }
}
int const Wine::sum()
{
    return PairArray::second().sum();
}


#endif
