#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
#include"f:\Фильмы\Язык программирования C++\Стивен Прата - Язык программирования C++\Examples\Chapter 14\stacktp.h"

template<template<typename T> typename Thing>

class Grab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Grab() {};
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }
};


#endif