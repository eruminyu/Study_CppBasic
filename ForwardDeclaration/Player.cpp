#include "Player.h"
#include "Weapon.h"

//Ctrl + K + O

Player::Player()
{
	weapon = new Weapon();
}

Player::~Player()
{
	if (weapon)
	{
		delete weapon;
	}
}
//RAII의 기본적인 방식.