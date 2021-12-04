#include "Header.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average() const
{
	if (ArrayDB::size() > 0)
		return ArrayDB::sum() / ArrayDB::size();
	else
		return 0;
}
const std::string& Student::Name() const
{
	return (const string&)*this;
}
double& Student::operator[](int i)
{
	return ArrayDB::operator[](i);
}
double Student::operator[](int i) const
{
	return ArrayDB::operator[](i);
}
std::ostream& Student::arr_out(std::ostream& os) const
{
	int i;
	int lim = ArrayDB::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; ++i)
		{
			os << ArrayDB::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 == 0)
			os << endl;
	}
	else
		os << "empty array ";
	return os;
}

//friend

std::istream& operator>>(std::istream& is, Student& stu)
{
	is >> (string&)stu;
	return is;
}
std::istream& getline(std::istream& is, Student& stu)
{
	getline(is, (string&)stu);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Student& stu)
{
	os << "Scores for " << (const string&)stu << ":\n";
	stu.arr_out(os);
	return os;
}
