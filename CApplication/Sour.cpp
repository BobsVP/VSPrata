#include<iostream>
#include<initializer_list>

template<typename T>
auto average_list(std::initializer_list<T> args)
{
	return args;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::initializer_list<T> args)
{
	for (auto i = args.begin(); i != args.end(); ++i)
		os << *i << std::endl;
	return os;
}

int main()
{
	using namespace std;
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;
	cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;
	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << endl;
	return 0;
}

