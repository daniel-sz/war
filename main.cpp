#include "Card.h"
#include <queue>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void deck(Card *, int);

int main(int argc, char const *argv[])
{
	
	srand(time(NULL));
	Card *cards = new Card[52];
	
	//uzupełnić o porównywanie, gracze-stosy
	deck(cards, 52);
	return 0;
}

void deck(Card * cards, int n)
{
	int where=0;
	//potasowanie talii kart
	vector <Card *> tempdeck;
	for (int i = 0; i < n; ++i)
	{
		tempdeck.insert(tempdeck.begin()+where,cards+i);
		where=rand()%tempdeck.size();
	}
	//przeniesienie z wektora do stosu
	stack <Card *> deck;
	for (int i = 0, x; i < n; ++i)
	{
		deck.push(tempdeck.back());
		tempdeck.erase(tempdeck.end()-1);
	}
	
	//wyświetlenie ułożenia kart w talii
	for (vector <Card *>::iterator iter=tempdeck.begin();iter != tempdeck.end();iter++)
	{
		
		cout<<(*iter)->description()<<", ";
		
	}
	
	queue <Card *> player1;
	queue <Card *> player2;
	for (int i = 0; i < 1; ++i)
	{
		player1.push(deck.top());
		deck.pop();
		player2.push(deck.top());
		deck.pop();
	}
	cout<<"Player1: ";
	for (int i = 0; i < 1; ++i)
	{
		cout<<player1.front()->description()<<", ";
		//player1.pop();
	}
	cout<<endl<<"Player2: ";
	for (int i = 0; i < 1; ++i)
	{
		cout<<player2.front()->description()<<", ";
		//player2.pop();
	}
	cout<<endl;
	char wynik=player1.front()->compare(player2.front());
	cout<<"Wynik: "<<wynik<<endl;
}
