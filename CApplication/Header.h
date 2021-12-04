#pragma once
#ifndef Header_h
#define Header_h

#include<iostream>
#include<string>
#include<valarray>

class Student :private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDB;
	std::ostream& arr_out(std::ostream& os) const;
public:
	Student() : std::string("Null Student"), ArrayDB() {}
	explicit Student(const std::string& s) : std::string(s), ArrayDB() {}
	explicit Student(int n) : std::string("Nully"), ArrayDB(n) {}
	Student(const std::string& s, int n) : std::string(s), ArrayDB(n) {}
	Student(const std::string& s, ArrayDB& a) : std::string(s), ArrayDB(a) {}
	Student(const char* str, const double& pd, int n) : std::string(str), ArrayDB(pd, n) {}
	~Student() {}
	double Average() const;
	const std::string& Name() const;
	double& operator[](int i);
	double operator[](int i) const;
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif
