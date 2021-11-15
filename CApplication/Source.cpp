#include "Header.h"
#include<iostream>
#include<cstring>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	int tmp = strlen(s1) + 1;
	performers = new char [tmp];
	strcpy_s(performers, tmp, s1);
	tmp = strlen(s2) + 1;
	label = new char[tmp];
	strcpy_s(label, tmp, s2);
	salections = n;
	playtime = x;
}
Cd::Cd(const Cd& d)
{
	int tmp = strlen(d.performers) + 1;
	performers = new char[tmp];
	strcpy_s(performers, tmp, d.performers);
	tmp = strlen(d.label) + 1;
	label = new char[tmp];
	strcpy_s(label, tmp, d.label);
	salections = d.salections;
	playtime = d.playtime;
}
Cd::Cd()
{
	performers = new char[1];
	performers[0] = '\0';
	label = new char[1];
	label[0] = '\0';
	salections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}
void Cd::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << salections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}
Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	int tmp = strlen(d.performers) + 1;
	performers = new char[tmp];
	strcpy_s(performers, tmp, d.performers);
	tmp = strlen(d.label) + 1;
	label = new char[tmp];
	strcpy_s(label, tmp, d.label);
	salections = d.salections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic()
{
	Fayvorits = new char[1];
	Fayvorits[0] = '\0';
}
Classic::Classic(const char* Fa, const char* s1, const char* s2, int n, double x) :Cd(s1, s2, n, x)
{
	int tmp = strlen(Fa) + 1;
	Fayvorits = new char[tmp];
	strcpy_s(Fayvorits, tmp, Fa);
}
Classic::Classic(const char* Fa, Cd& cd) : Cd(cd)
{
	int tmp = strlen(Fa) + 1;
	Fayvorits = new char[tmp];
	strcpy_s(Fayvorits, tmp, Fa);
}
void Classic::Report() const
{
	Cd::Report();
	std::cout << "Fayvorits: " << Fayvorits << std::endl;
}
Classic::~Classic()
{
	delete[] Fayvorits;
}

Classic& Classic::operator=(const Classic & d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete[] Fayvorits;
	int tmp = strlen(d.Fayvorits) + 1;
	Fayvorits = new char[tmp];
	strcpy_s(Fayvorits, tmp, d.Fayvorits);
	return *this;
}
