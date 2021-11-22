#include "Header.h"
#include <cstring>

AbstractDMA::AbstractDMA(const char* l, int r)
{
    label = new char[std::strlen(l) + 1];
    strcpy_s(label, std::strlen(l) + 1, l);
    rating = r;
}

AbstractDMA::AbstractDMA(const AbstractDMA& rs)
{
    label = new char[std::strlen(rs.label) + 1];
    strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
    rating = rs.rating;
}

//AbstractDMA::AbstractDMA()
//{
//    label = new char[1];
//    label[0] = '\0';
//    rating = 0;
//}

AbstractDMA::~AbstractDMA()
{
    delete[] label;
}

AbstractDMA& AbstractDMA::operator=(const AbstractDMA& rs)
{
    if (this == &rs)
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
    rating = rs.rating;
    return *this;
}

void AbstractDMA::View()
{
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}


// baseDMA methods
baseDMA::baseDMA(const char* l, int r):AbstractDMA(l, r)
{
}

baseDMA::baseDMA(const baseDMA& rs) : AbstractDMA(rs)
{
}

baseDMA::baseDMA() : AbstractDMA()
{
}

baseDMA::~baseDMA()
{
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
    if (this == &rs)
        return *this;
    AbstractDMA::operator=(rs);
    return *this;
}

void baseDMA::View()
{
    AbstractDMA::View();
}

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
    : AbstractDMA(l, r)
{
    strncpy_s(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const lacksDMA& rs)
    : AbstractDMA(rs)
{
    strncpy_s(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View()
{
    AbstractDMA::View();
    std::cout << "Color: " << color << std::endl;
}

lacksDMA::~lacksDMA()
{
}


// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r)
    : AbstractDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    strcpy_s(style, std::strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const hasDMA& rs)
    : AbstractDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    strcpy_s(style, std::strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA& hs)
    : AbstractDMA(hs)  
{
    style = new char[std::strlen(hs.style) + 1];
    strcpy_s(style, std::strlen(hs.style) + 1, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
    if (this == &hs)
        return *this;
    AbstractDMA::operator=(hs);  
    delete[] style;         
    style = new char[std::strlen(hs.style) + 1];
    strcpy_s(style, std::strlen(hs.style) + 1, hs.style);
    return *this;
}

void hasDMA::View()
{
    AbstractDMA::View();
    std::cout << "Style: " << style << std::endl;
}
