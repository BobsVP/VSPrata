#ifndef Header_h
#define Header_h

#include<iostream>
using namespace std;

class Port
{
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port() { delete[] brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int Botlecount() const { return bottles; }
	virtual void Show() const;
	friend ostream& operator<<(ostream& os, const Port& p);

private:
	char* brand;
	char style[20];
	int bottles;
};

class VintagePort: public Port
{
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort() { delete[] nickname;	}
	VintagePort& operator=(const VintagePort& vp);
	void Show() const;
	friend ostream& operator<<(ostream& os, const VintagePort& p);

private:
	char* nickname;
	int year;
};

#endif
// Переопределяются те функции которые нужно расширить. Конструкторы и деструкторы для каждого класса свои.
//Присваивание не наследуется(разные сигнатуры), дружественные функции не наследуются поскольку не являются
//членами класса