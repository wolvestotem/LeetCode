#include<iostream>
#include<string>
#include"classdef01.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Plorg joker{"joker",30};
	Plorg kitty = Plorg("Kitty",29);
	Plorg plorga;

	joker.declaration();
	kitty.declaration();
	plorga.declaration();
	
	joker.rewrite(10);
	kitty = joker;

	joker.declaration();
	kitty.declaration();

	return 0;
}