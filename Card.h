#pragma once
#include <string>

using namespace std;

enum result
{
	win='1',
	draw='x',
	lost='0'
};

class Card
{
	private:
		int color,value;
		static int counter;
	public:
		string description();
		Card();
		result compare(Card *);
};