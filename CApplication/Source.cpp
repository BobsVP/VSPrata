#include "Header.h"
#include<cstring>

// class Port metods
Port::Port(const char* br, const char* st, int b)
{
	brand = new char[std::strlen(br) + 1];
	strcpy_s(brand, std::strlen(br) + 1, br);
	strcpy_s(style, strlen(st) + 1, st);
	bottles = b;
}
Port::Port(const Port& p)
{
	this->brand = new char[std::strlen(p.brand) + 1];
	strcpy_s(this->brand, std::strlen(p.brand) + 1, p.brand);
	strcpy_s(this->style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
}
Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	delete[] brand;
	this->brand = new char[std::strlen(p.brand) + 1];
	strcpy_s(this->brand, std::strlen(p.brand) + 1, p.brand);
	strcpy_s(this->style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
	return *this;
}
Port& Port::operator+=(int b)
{
	this->bottles = this->bottles + b;
	return *this;
}
Port& Port::operator-=(int b)
{
	if (this->bottles < b)
		std::cout << "Port wine is over" << std::endl;
	else
		this->bottles = this->bottles - b;
	return *this;

}
void Port::Show() const
{
	std::cout << "\nBrand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}
ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}


//class VintagePort metods
VintagePort::VintagePort():Port()
{
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y):Port(br, "vintage", b)
{
	nickname = new char[std::strlen(nn) + 1];
	strcpy_s(nickname, std::strlen(nn) + 1, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	strcpy_s(nickname, std::strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;

}
VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	this->nickname = new char[std::strlen(vp.nickname) + 1];
	strcpy_s(this->nickname, std::strlen(vp.nickname) + 1, vp.nickname);
	this->year = vp.year;
	return *this;

}
void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}
ostream& operator<<(ostream& os, const VintagePort& p)
{
	os << p.nickname << ", ";
	os << (Port&)p;
	return os;
}