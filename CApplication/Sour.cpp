#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

auto outint = [](int n) { std::cout << n << " "; };

int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	cout << "Original list:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([](const int & v) { return v > 100; });
	etcetera.remove_if([](const int& v) { return v > 200; });
	yadayada.sort();
	etcetera.sort();
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for (auto &st : etcetera)
		cout << st << " ";
	cout << endl;
	return 0;
}
