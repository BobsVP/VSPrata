#ifndef Header_h
#define Header_h

class Cd
{
private:
	char performers[50];
	char label[20];
	int salections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

class Classic :public Cd
{
private:
	char Fayvorits[80];
public:
	Classic();
	Classic(const char* Fa, const char* s1, const char* s2, int n, double x);
	Classic(const char* Fa, Cd& cd);
	virtual void Report() const;
	~Classic();
};

#endif
