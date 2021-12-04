﻿#include<iostream>
#include"Header.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);
const int puppils = 3;
const int quizzes = 5;

int main()
{
	Student ada[puppils] = { Student(quizzes), Student(quizzes), Student(quizzes) };
	int i;
	for (i = 0; i < puppils; ++i)
		set(ada[i], quizzes);
	cout << "\nStudent List: \n";
	for (i = 0; i < puppils; ++i)
		cout << ada[i].Name() << endl;
	cout << "\nResults: ";
	for (i = 0; i < puppils; ++i)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "Done.\n";
	return 0;
}

void set(Student& sa, int n)
{
	cout << "Enter the student's name: ";
	getline(cin, sa);
	cout << "Please enter " << n << " quiz scores: \n";
	for (int i = 0; i < n; ++i)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}
