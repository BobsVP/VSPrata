#include<iostream>

long double sum_values()
{
	return 0;
}

template<typename T>
long double sum_values(T value)
{
	static_cast<long double>(value);
	return value;
}

template<typename T, typename ... Args>
long double sum_values(T value, Args...arg)
{
	static_cast<long double>(value);
	return value + sum_values(arg...);
}

int main()
{
	std::cout << sum_values() << std::endl;
	std::cout << sum_values(1) << std::endl;
	std::cout << sum_values(0, 2, 41.41, '\t', '\n', 10.98, 14) << std::endl;
	return 0;
}

