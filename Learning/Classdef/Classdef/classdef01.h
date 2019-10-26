#pragma once
#include<iostream>
#include<string>

class Plorg {
private:
	std::string name;
	int CI;
public:
	Plorg(const std::string & na="Plorga",int C=50 );
	void rewrite(int newCI);
	void declaration() const;
};