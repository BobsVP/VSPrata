#ifndef Header_h
#define Header_h

#include <iostream>

class AbstractDMA
{
public:
    AbstractDMA(const char* l = "null", int r = 0);
    AbstractDMA(const AbstractDMA& rs);
    //AbstractDMA();
    virtual ~AbstractDMA() = 0;
    AbstractDMA& operator=(const AbstractDMA& rs);
    virtual void View();
private:
    char* label;
    int rating;
};


class baseDMA :public AbstractDMA
{
private:

public:
    baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA& rs);
    baseDMA();
    virtual ~baseDMA();
    baseDMA& operator=(const baseDMA& rs);
    virtual void View();
};

class lacksDMA :public AbstractDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char* l = "null",
        int r = 0);
    lacksDMA(const char* c, const lacksDMA& rs);
    virtual void View();
    virtual ~lacksDMA();
};

class hasDMA :public AbstractDMA
{
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null",
        int r = 0);
    hasDMA(const char* s, const hasDMA& rs);
    hasDMA(const hasDMA& hs);
    ~hasDMA();
    hasDMA& operator=(const hasDMA& rs);
    virtual void View();
};

#endif
