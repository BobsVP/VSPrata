#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
const int MAX = 10;

void ShowEntry(abstr_emp** pc);
int DeleteEntry(int s, abstr_emp** pc);
int ininput(int start, int end);
int FreeIndex(abstr_emp* pc[]);

int main(int argc, char * argv[])
{
	const std::string fileName = "employees.dat";
	abstr_emp* pc[MAX]{ nullptr };
	std::ifstream FileData(fileName);
	if (FileData.is_open())
	{
		int classtype;
		int counter = 0;
		while (FileData >> classtype && (classtype > 4 && classtype < 9))
		{
			FileData.get();
			switch (classtype)
			{
			case 5: pc[counter] = new employee;
				pc[counter]->GetAll(FileData);
				break;
			case 6:pc[counter] = new manager;
				pc[counter]->GetAll(FileData);
				break;
			case 7:pc[counter] = new fink;
				pc[counter]->GetAll(FileData);
				break;
			case 8:pc[counter] = new highfink;
				pc[counter]->GetAll(FileData);
				break;
			}
			counter++;
		}
		cout << "The file " << fileName << " contains the following entries : \n";
		ShowEntry(pc);
	}
	FileData.close();
	bool repeat = true;
	while (repeat)
	{
		cout << "What do you want to do?" << endl;
		cout << "1. Add new entry" << endl;
		cout << "2. Delete entry" << endl;
		cout << "3. Show current entries" << endl;
		cout << "4. Save & Exit" << endl;
		cout << ">";
		int s;
		s = ininput(1, 4);
		switch (s)
		{
		case 1: cout << "What type to create?" << endl;
			cout << "5. Employee" << endl;
			cout << "6. Manger" << endl;
			cout << "7. Fink" << endl;
			cout << "8. Highfink" << endl;
			s = ininput(5, 8);
			switch (s)
			{
				int index;
			case 5:index = FreeIndex(pc);
				if (index != -1)
				{
					pc[index] = new employee;
					pc[index]->SetAll();
				}
				else
					std::cerr << "No free cell." << endl;
				break;
			case 6:index = FreeIndex(pc);
				if (index != -1)
				{
					pc[index] = new manager;
					pc[index]->SetAll();
				}
				else
					std::cerr << "No free cell." << endl;
				break;
			case 7:index = FreeIndex(pc);
				if (index != -1)
				{
					pc[index] = new fink;
					pc[index]->SetAll();
				}
				else
					std::cerr << "No free cell." << endl;
				break;
			case 8:index = FreeIndex(pc);
				if (index != -1)
				{
					pc[index] = new highfink;
					pc[index]->SetAll();
				}
				else
					std::cerr << "No free cell." << endl;
				break;
			}
			break;
		case 2: cout << "Enter the number entry to delete: ";
			s = ininput(1, 10);
			if (DeleteEntry(s, pc) == -1)
				std::cerr << "Bad number entry." << endl;
			break;
		case 3: ShowEntry(pc);
			break;
		case 4: repeat = false;
			std::ofstream FileData(fileName);
			for (int i = 0; i < MAX; i++)
			{
				if (pc[i] != nullptr)
				{
					int TypeEntry = 5;
					if (dynamic_cast<highfink*>(pc[i]))
						TypeEntry = 8;
					else if (dynamic_cast<fink*>(pc[i]))
						TypeEntry = 7;
					else if (dynamic_cast<manager*>(pc[i]))
						TypeEntry = 6;
					FileData << TypeEntry << endl;
					pc[i]->WriteAll(FileData);
					delete pc[i];
				}
			}
			FileData.close();
			break;
		}
	}
	return 0;
}

int ininput(int start, int end)
{
	int num = 0;
	while (num == 0)
	{
		cin >> num;
		if (cin.fail() && !cin.eof())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			std::cerr << "Incorrect input. Try again: ";
			continue;
		}
		if (num < start || num > end)
		{
			std::cerr << "Incorrect choice. Try again: ";
			num = 0;
		}
		cin.ignore(32767, '\n');
	}
	return num;
}

void ShowEntry(abstr_emp** pc)
{
	int counter = 0;
	for (int x = 0; x < MAX; ++x)
		if (*(pc + x) != nullptr)
		{
			counter++;
			cout << "\t\tEntry #" << counter << endl;
			pc[x]->ShowAll();
		}
	if (counter == 0)
		std::cerr << "No entries. \n";
}
int FreeIndex(abstr_emp* pc[])
{
	for (int x = 0; x < MAX; ++x)
		if (*(pc + x) == nullptr)
			return x;
	return -1;
}
int DeleteEntry(int s, abstr_emp** pc)
{
	int counter = 0;
	for (int x = 0; x < MAX; ++x)
		if (*(pc + x) != nullptr)
		{
			counter++;
			if (counter == s)
			{
				delete *(pc + x);
				*(pc + x) = nullptr;
				return x;
			}
		}
	return -1;
}

