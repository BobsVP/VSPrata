#include"Header.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

const int NUM = 10;

int main()
{
	std::srand(std::time(0));
	std::cout << "Please enter stack size: ";
	int stacksize;
	std::cin >> stacksize;
	Stack<const char*> st(stacksize);
	const char* in[NUM] = {
		"1: Hank Gilgamesh", "2: Kiki Ishtar",
		"3: Betty Rocker", "4: Ian Flagranty",
		"5: Wolfgang Kibble", "6: Portia Koop",
		"7: Joy Almondo", "8: Xaverie Paprica",
		"9: Juan Moor", "10: Misha Mashe"
	};
	const char* out[NUM];
	int processed = 0;
	int nextin = 0; 
	while (processed < NUM)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < NUM)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < NUM; i++)
		std::cout << out[i] << std::endl;
	std::cout << "Bye!\n";
	return 0;
}

