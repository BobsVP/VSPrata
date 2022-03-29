#pragma once
#ifndef Header_h
#define Header_h

#include <iostream>
#include <stdexcept> 

class BaseLogic : public std::logic_error
{
public:
    BaseLogic(const char* s, double first, double second);
    virtual void GetData() const {}
	virtual ~BaseLogic();

protected:
    double v1;
    double v2;
};

BaseLogic::BaseLogic(const char* s, double first, double second) : std::logic_error(s), v1(first), v2(second)
{
}

BaseLogic::~BaseLogic()
{
}

class bad_hmean : public BaseLogic
{
private:
public:
    bad_hmean(const char* s, double first, double second) : BaseLogic(s, first, second) {}
    virtual void GetData() const;
};

void bad_hmean::GetData() const
{
    std::cout << this->what() << ", argument #1: " << this->v1 << ", argument #2: " << this->v2 << std::endl;
}

class bad_gmean : public BaseLogic
{
public:
    bad_gmean(const char* s, double first, double second) : BaseLogic(s, first, second) {}
    virtual void GetData() const;
};

void bad_gmean::GetData() const
{
    std::cout << this->what() << ", argument #1: " << this->v1 << ", argument #2: " << this->v2 << std::endl;
}


#endif