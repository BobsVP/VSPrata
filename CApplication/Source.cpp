#include"Header.h"
#include <sstream>

//abstr_emp metods
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
{
fname = fn;
lname = ln;
job = j;
}

void abstr_emp::ShowAll() const
{
	std::cout << "Name: " << fname << std::endl;
	std::cout << "Family: " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
	std::cout << "Enter name: ";
	std::getline(std::cin, fname);
	std::cout << "Enter family: ";
	std::getline(std::cin, lname);
	std::cout << "Enter job: ";
	std::getline(std::cin, job);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << std::endl << e.fname << " " << e.lname ;
	return os;
}

abstr_emp::~abstr_emp()
{}

//employee metods
employee::employee(const std::string& fn, const std::string& ln, const std::string& j):
	abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

employee::~employee()
{
}

//manager metods
manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico):
	abstr_emp(fn, ln, j), inchargeof(ico)
{
}
manager::manager(const abstr_emp& e, int ico):
	abstr_emp(e), inchargeof(ico)
{
}
manager::manager(const manager& m)
{
	*this = m;
}
void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "InChangeOf: " << inchargeof << std::endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter the InChangeOf: ";
	std::cin >> inchargeof;
}
manager::~manager()
{}

//fink metods
fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo):
	abstr_emp(fn, ln, j), reportsto(rpo)
{
}
fink::fink(const abstr_emp& e, const std::string& rpo):
	abstr_emp(e), reportsto(rpo)
{
}
fink::fink(const fink& e)
{
	*this = e;
}
void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Reportsto: " << reportsto << std::endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter the Reportsto: ";
	std::cin >> reportsto;
}

fink::fink()
{
}
fink::~fink()
{
}

//highfink metods
highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico):
	abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)
{}
highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico):
	abstr_emp(e), fink(e, rpo), manager(e, ico)
{}
highfink::highfink(const fink& f, int ico):
	abstr_emp(f), fink(f), manager(f, ico)
{}
highfink::highfink(const manager& m, const std::string& rpo):
	abstr_emp(m), manager(m), fink(m, rpo)
{}
highfink::highfink(const highfink& h)
{
	*this = h;
}
void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "InChangeOf: " << InChangeOf() << std::endl;
	std::cout << "Reportsto: " << ReportsTo() << std::endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter the InChangeOf: ";
	std::cin >> InChangeOf();
	std::cout << "Enter the Reportsto: ";
	std::cin >> ReportsTo();
}

highfink::highfink()
{
}
highfink::~highfink()
{
}
