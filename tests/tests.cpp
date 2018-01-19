#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include  "../src/death_square.hpp"



TEST_CASE("Testing_card_class"){
	Card new_card = Card(3);
	try {Card card2 = Card(1);}
	catch (int e){
		REQUIRE(e == 1); 
	}
	REQUIRE(new_card.return_value() == 3);
}

TEST_CASE("Testing_position_class"){
	Card card1 = Card(5);
	Card card2 = Card(14);
	Position pos1 = Position();
	pos1.add_to_history(card1);
	pos1.add_to_history(card2);
	vector<Card> history = pos1.get_history();
	REQUIRE(history[0].return_value() == 5);
	REQUIRE(history[1].return_value() == 14);
}

TEST_CASE("Testing_game_class"){
	vector<Card> cards;
	vector<int> positions;
	for(int i=0; i<9; i++){
		Card new_card = Card(i+2);
		cards.push_back(new_card);
		positions.push_back(i);
	}
	Game game = Game(positions,cards);

	SECTION("Testing the basic mechanics"){
		Position pos1 = game.get_position(0);
		REQUIRE(pos1.get_history()[0].return_value() == 2);
	}
}

