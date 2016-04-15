#include "Card.h"
#include <string>
using namespace std;

int Card::counter=0;

result Card::compare(Card * a)
{
	if (this->value>a->value) return win;
	else if (this->value<a->value) return lost;
	else return draw;
}
Card::Card()
{
	color=counter/13;
	value=counter++%13;
}
string Card::description()
{
	//♥♠♣♦
	static char colors[]="KPTR";
	static char values[]="234567890JQKA";
	return string(1,colors[color])+string(1,values[value]);
}