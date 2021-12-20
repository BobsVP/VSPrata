#include"Header.h"
#include<iostream>
#include<string>

int main()
{
	using std::cout;
	using std::endl;
	using std::string;
	Pairs<string, int> ratings[4] =
	{
		Pairs<string, int>("The Purpled Duck", 5),
		Pairs<string, int>("Jaquie's Frisko Al Fresco", 4),
		Pairs<string, int>("Caffe Soufle", 5),
		Pairs<string, int>("Bertie's Eats", 3)
	};
	int joints = sizeof(ratings) / sizeof(Pairs<string, int>);
	cout << "Rating:\t Eatery\n";
	for (int i = 0; i < joints; i++)
		cout << ratings[i].second() << ":\t" << ratings[i].first() << endl;
	cout << "Oops! Revised rating:\n";
	ratings[3].first() = "Bertie's Fab Eats";
	ratings[3].second() = 6;
	cout << ratings[3].second() << ":\t" << ratings[3].first() << endl;
	return 0;
}

