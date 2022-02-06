#include"Header.h"
#include<iostream>
using namespace std;

int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew");
	cout << hf << endl;
	hf.ShowAll();
	cout << "Press a key for next phase: \n";
	cin.get();
	highfink hf2;
	hf2.SetAll();
	cout << "\nUsing an abstr_emp* pointer:\n";
	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
	return 0;
}

//Достаточно операции присваивания по умолчанию
//методы SetAll и ShowAll виртуальные что бы можно было переопределять и вызывать их для каждого класса и с указателем
//класс abstr_emp наследуется как виртуальный класс
//в классе highfink используются данные от родительских классов
//operator<<() выводит данные только класса abstr_emp
//не удастся объявить массив абстрактного класса abstr_emp а если все-таки создать то в массиве будет только часть содержащая родительский класс 