#include<iostream>
#include"Header.h"
#include<cstring>

const int COL_CH = 4;

int main()
{
	Port* Sklad[COL_CH];
	char tmpbrand[80];
	char tmpstyle[20];
	int tmpbottles;
	for (int i = 0; i < COL_CH; ++i)
	{
		std::cout << "Enter the brand: ";
		std::cin.getline(tmpbrand, 79, '\n');
		std::cout << "Enter the style: ";
		std::cin.getline(tmpstyle, 19, '\n');
		std::cout << "Enter the bottles: ";
		std::cin >> tmpbottles;
		std::cin.get();
		if (!(strcmp(tmpstyle, "vintage")))
		{
			char tmpnickname[80];
			int tmpyear;
			std::cout << "Enter the nickname: ";
			std::cin.getline(tmpnickname, 79, '\n');
			std::cout << "Enter the year: ";
			std::cin >> tmpyear;
			std::cin.get();
			Sklad[i] = new VintagePort(tmpbrand, tmpbottles, tmpnickname, tmpyear);
		}
		else
			Sklad[i] = new Port(tmpbrand, tmpstyle, tmpbottles);
	}
	for (int i = 0; i < COL_CH; ++i)
	{
		std::cout << "Collection #" << i + 1;
		Sklad[i]->Show();
	}
	std::cout << "Enter the number of coleection (1, 2, 3 or 4; q to quit):";
	int target;
	while (std::cin >> target)
	{
		std::cin.get();
		if (target > 0 && target < 5)
		{
			std::cout << "Want to add port to your collection (y or n): ";
			char tmp;
			std::cin.get(tmp);
			while (cin.get() != '\n')
				continue;
			if (tmp == 'y')
			{
				std::cout << "Enter the number of bottles: ";
				int tmpbottles;
				std::cin >> tmpbottles;
				std::cin.get();
				*Sklad[target-1] += tmpbottles;
			}
			else
			{
				std::cout << "Want to take port from your collection (y or n): ";
				std::cin.get(tmp);
				while (cin.get() != '\n')
					continue;
				if (tmp == 'y')
				{
					std::cout << "Enter the number of bottles: ";
					int tmpbottles;
					std::cin >> tmpbottles;
					std::cin.get();
					*Sklad[target - 1] -= tmpbottles;
				}

			}
		}
		std::cout << "Enter the number of coleection (1, 2, 3 or 4; q to quit):";
	}
	for (int i = 0; i < COL_CH; ++i)
		delete[] Sklad[i];
	std::cout << "Done!";
	return 0;
}

