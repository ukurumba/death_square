#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iterator>

using namespace std;

class Card{
	int value; 
public:
	Card(int val);
	int get_value();
};

class Position{
	vector<Card> history; 

public:
	Position();
	vector<Card> get_history();
	void add_to_history(Card card);
};

class Game{
	vector<Card> cards_in_deck; 
public:
	Game();
	Game resize(vector<int> remaining_positions);
	void undo();
	void update_history(Card card, int position);	
	void modify_cards_in_deck(vector<Card> new_deck);
	void over_under(); 
};