#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
#include<string>

class abstr_emp
{
public:
	abstr_emp() {};
	abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual std::ifstream& GetAll(std::ifstream& fs);
	virtual std::ofstream& WriteAll(std::ofstream& fs);
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() = 0;

private:
	std::string fname;
	std::string lname;
	std::string job;
};

class employee :public abstr_emp
{
public:
	employee() {};
	employee(const std::string& fn, const std::string& ln, const std::string& j);
	void ShowAll() const override;
	void SetAll() override;
	std::ifstream& GetAll(std::ifstream& fs) override;
	std::ofstream& WriteAll(std::ofstream& fs) override;
	~employee();
};

class manager : virtual public abstr_emp
{
public:
	manager() {};
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	void ShowAll() const override;
	void SetAll() override;
	std::ifstream& GetAll(std::ifstream& fs) override;
	std::ofstream& WriteAll(std::ofstream& fs) override;
	~manager();
protected:
	int InChangeOf() const { return inchargeof; }
	int& InChangeOf() { return inchargeof; }
private:
	int inchargeof;
};

class fink : virtual public abstr_emp
{
public:
	fink();
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& e);
	void ShowAll() const override;
	void SetAll() override;
	std::ifstream& GetAll(std::ifstream& fs) override;
	std::ofstream& WriteAll(std::ofstream& fs) override;
	~fink();
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }
private:
	std::string reportsto;
};

class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);
	void ShowAll() const override;
	void SetAll() override;
	std::ifstream& GetAll(std::ifstream& fs) override;
	std::ofstream& WriteAll(std::ofstream& fs) override;
	~highfink();
};

#endif