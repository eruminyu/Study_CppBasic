#include "Player.h"
#include <iostream>

int main()
{

	std::unique_ptr<int> Test;

	Player* player1 = new Player();
	Player* player2 = new Player("Minsung");
	Player* player3 = new Player(*player2);

	delete player1;
	delete player2;
	delete player3;

	Player* player4 = player3;

	//std::cin.get();

}