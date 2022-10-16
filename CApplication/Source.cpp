#include"Header.h"
#include <fstream>

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

std::ifstream& abstr_emp::GetAll(std::ifstream& fs)
{
	std::getline(fs, fname);
	std::getline(fs, lname);
	std::getline(fs, job);
	return fs;
}

std::ofstream& abstr_emp::WriteAll(std::ofstream& fs)
{
	fs << fname << std::endl;
	fs << lname << std::endl;
	fs << job << std::endl;
	return fs;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << std::endl << e.fname << " " << e.lname;
	return os;
}

abstr_emp::~abstr_emp()
{}

//employee metods
employee::employee(const std::string& fn, const std::string& ln, const std::string& j) :
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

std::ifstream& employee::GetAll(std::ifstream& fs)
{
	abstr_emp::GetAll(fs);
	return fs;
}

std::ofstream& employee::WriteAll(std::ofstream& fs)
{
	abstr_emp::WriteAll(fs);
	return fs;
}

employee::~employee()
{
}

//manager metods
manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) :
	abstr_emp(fn, ln, j), inchargeof(ico)
{
}
manager::manager(const abstr_emp& e, int ico) :
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
std::ifstream& manager::GetAll(std::ifstream& fs)
{
	abstr_emp::GetAll(fs);
	fs >> inchargeof;
	fs.ignore(255, '\n');
	return fs;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter the InChangeOf: ";
	std::cin >> inchargeof;
}
std::ofstream& manager::WriteAll(std::ofstream& fs)
{
	abstr_emp::WriteAll(fs);
	fs << inchargeof << std::endl;
	return fs;
}
manager::~manager()
{}

//fink metods
fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) :
	abstr_emp(fn, ln, j), reportsto(rpo)
{
}
fink::fink(const abstr_emp& e, const std::string& rpo) :
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
	std::getline(std::cin, reportsto);
}
std::ifstream& fink::GetAll(std::ifstream& fs)
{
	abstr_emp::GetAll(fs);
	std::getline(fs, reportsto);
	return fs;
}
std::ofstream& fink::WriteAll(std::ofstream& fs)
{
	abstr_emp::WriteAll(fs);
	fs << reportsto << std::endl;
	return fs;
}
fink::fink()
{
}
fink::~fink()
{
}

//highfink metods
highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) :
	abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)
{}
highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) :
	abstr_emp(e), fink(e, rpo), manager(e, ico)
{}
highfink::highfink(const fink& f, int ico) :
	abstr_emp(f), fink(f), manager(f, ico)
{}
highfink::highfink(const manager& m, const std::string& rpo) :
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
std::ifstream& highfink::GetAll(std::ifstream& fs)
{
	abstr_emp::GetAll(fs);
	fs >> InChangeOf();
	fs >> ReportsTo();
	return fs;
}
std::ofstream& highfink::WriteAll(std::ofstream& fs)
{
	abstr_emp::WriteAll(fs);
	fs << InChangeOf() << std::endl;
	fs << ReportsTo() << std::endl;
	return fs;
}
highfink::highfink()
{
}
highfink::~highfink()
{
}