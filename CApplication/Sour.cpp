#include<iostream>
#include<string>
#include"Header.h"

int main()
{
	Cpmv obj0;
	Cpmv obj1("Hello ", "Good ");
	obj1.Display();
	Cpmv obj2(obj1);
	obj2.Display();
	Cpmv obj3(obj0 + Cpmv{"World", "Morning"});
	obj0 = obj1;
	obj0.Display();
	obj2 = obj0 + obj3;
	obj2.Display();
	obj2 += Cpmv{ ",", "." };
	obj2.Display();
	return 0;
}

