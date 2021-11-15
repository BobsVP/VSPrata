#include "Header.h"
#include<iostream>
#include<cstring>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	//int tmp = strlen(s1) + 1;
	strcpy_s(performers, s1);
	strcpy_s(label, s1);
	salections = n;
	playtime = x;
}
Cd::Cd(const Cd& d)
{
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	salections = d.salections;
	playtime = d.playtime;
}
Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	salections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{}
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
	strcpy_s(this->performers, d.performers);
	strcpy_s(this->label, d.label);
	this->salections = d.salections;
	this->playtime = d.playtime;
	return *this;
}

Classic::Classic()
{
	Fayvorits[0] = '\0';
}
Classic::Classic(const char* Fa, const char* s1, const char* s2, int n, double x) :Cd(s1, s2, n, x)
{
	strcpy_s(Fayvorits, Fa);
}
Classic::Classic(const char* Fa, Cd& cd) : Cd(cd)
{
	strcpy_s(Fayvorits, Fa);
}
void Classic::Report() const
{
	Cd::Report();
	std::cout << "Fayvorits: " << Fayvorits << std::endl;
}
Classic::~Classic()
{}
