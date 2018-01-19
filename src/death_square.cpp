#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iterator>
#include <ctime>

using namespace std;

#include "death_square.hpp"

//Error Message 1: Invalid card value

Card::Card(int val){
	if (val < 2 || val > 14) {
		throw 1;
	}
	value = val;
}

int Card::return_value(){
	return value; 
}


Position::Position(){
	vector<Card> history;
}

vector<Card> Position::get_history(){
	return history;
}

void Position::add_to_history(Card card){
	history.push_back(card); 
}

Game::Game(vector<int> pos, vector<Card> cards){
	for(int i=0; i<pos.size(); i++){
		Position pos = Position();
		pos.add_to_history(cards[i]);
		positions.push_back(pos);
	}

}

Position Game::get_position(int pos_number){
	return positions[pos_number];
}
