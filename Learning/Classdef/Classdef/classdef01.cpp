
#include<iostream>
#include "classdef01.h"
#include<string>

Plorg::Plorg(const std::string & na, int C)
{
	name = na;
	CI = C;
}

void Plorg::rewrite(int newCI)
{
	CI = newCI;
}

void Plorg::declaration() const
{
	std::cout << "name of object:" << name << std::endl;
	std::cout << "CI:" << CI << std::endl;
}
