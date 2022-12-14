#pragma once
#ifndef Header_h
#define Header_h
class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv);
	~Cpmv();
	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& cp);
	Cpmv& operator+=(const Cpmv& cp);
	Cpmv operator+(const Cpmv& obj);
	void Display() const;
};

Cpmv::Cpmv()
{
	pi = new Info;
	std::cout << "Default constructor" << std::endl;
}
Cpmv::Cpmv(std::string q, std::string z) : pi(new Info{ q,z })
{
	std::cout << "String constructor" << std::endl;
}
Cpmv::Cpmv(const Cpmv& cp) : pi(new Info)
{
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	std::cout << "Copy constructor" << std::endl;
}
Cpmv::Cpmv(Cpmv&& mv)
{
	pi = nullptr;
	std::swap(pi, mv.pi);
	std::cout << "Move constructor" << std::endl;
}
Cpmv::~Cpmv()
{
	delete pi;
	std::cout << "Destructor" << std::endl;
}
Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	if (this == &cp)
		return *this;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	std::cout << "Copy operator=" << std::endl;
	return *this;
}
Cpmv& Cpmv::operator=(Cpmv&& cp)
{
	if (this == &cp)
		return *this;
	std::swap(pi, cp.pi);
	std::cout << "Move operator=" << std::endl;
	return *this;
}
Cpmv& Cpmv::operator+=(const Cpmv& cp)
{
	pi->qcode = pi->qcode + cp.pi->qcode;
	pi->zcode = pi->zcode + cp.pi->zcode;
	std::cout << "Operator+=" << std::endl;
	return *this;
}
Cpmv Cpmv::operator+(const Cpmv& obj)
{
	Cpmv tmp;
	tmp.pi->qcode = pi->qcode + obj.pi->qcode;
	tmp.pi->zcode = pi->zcode + obj.pi->zcode;
	std::cout << "Operator+" << std::endl;
	return tmp;
}
void Cpmv::Display() const
{
	std::cout << pi->qcode << std::endl;
	std::cout << pi->zcode << std::endl;
}

#endif