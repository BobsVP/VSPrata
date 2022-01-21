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

class Wine :private std::valarray<int>, std::string
{
private:
	//std::string label;
    int ColYear;
    //PairArray YearCount;
public:
    //Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);
    ~Wine() { }
 //   void GetBottles();
	//void Show() const;
    std::string Label() { return (const std::string&)(*this); }
	//int const sum();
};

//Wine::Wine(const char* l, int y, const int yr[], const int bot[]) :
//    label(l), ColYear(y)
//{
//    ArraiInt z(y);
//     YearCount = PairArray(z, z);
//   for (int i = 0; i < ColYear; ++i)
//    {
//       YearCount.first()[i] = yr[i];
//       YearCount.second()[i] = bot[i];
//   }
//
//}
Wine::Wine(const char* l, int y):std::string(l), ColYear(y)
{
    ArraiInt z(y);
    *this = Pair<ArraiInt, ArraiInt>(z, z);
}
//void Wine::GetBottles()
//{
//    for (int i = 0; i < ColYear; ++i)
//    {
//        std::cout << "Enter year: ";
//        int ttmp;
//        std::cin >> ttmp;
//        YearCount.first()[i] = ttmp;
//        std::cout << "Enter bottles for that year: ";
//        std::cin >> ttmp;
//        YearCount.second()[i] = ttmp;
//    }
//}
//void Wine::Show() const
//{
//    std::cout << "Wine: " << label << endl;
//    std::cout << "\tYear" << "\tBottles" << endl;;
//    for (int i = 0; i < ColYear; ++i)
//    {
//        std::cout << "\t" << YearCount.first()[i] << "\t" << YearCount.second()[i] << endl;;
//    }
//}
//int const Wine::sum()
//{
//    return YearCount.second().sum();
//}


#endif
