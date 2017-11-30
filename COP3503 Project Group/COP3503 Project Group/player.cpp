//
//  player.cpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#include <iostream>
#include <cstdlib.h>
#include "player.hpp"

Player::Player(std::string n) : hp(20), maxhp(20), str(10), def(10), sta(10), exp(0), level(1), maxexp(30), name(n) // Placeholder default values. Requires playtesting.
{
	inventory = {"None", "None", "None", "None", "None"};
}

void Player::levelUp()
{
	maxhp += (rand() % 7 + 3);
	//hp = maxhp // Uncomment if we need to heal the player upon level-up.
	str += (rand() % 3 + 1);
	def += (rand() % 3 + 1);
	sta += (rand() % 3 + 1);
	exp = maxexp - exp;
	maxexp += 10;
	level++;
	// Placeholder values. Playtest these!
}

int Player::die()
{
	std::cout << "Alas, brave warrior, you are slain! Expect another semester of COP 3502 in your future.\n";
	std::cout << "Your stats were:\n";
	displayStatus();
	exit(0);
	return 0;
}

std::string getType()
{
	return "Player";
}

void Player::heal(int h)
{
	hp += h;
	if (hp > maxhp) hp = maxhp;
}

std::string * Player::getInv()
{
	return inventory;
}

void Player::displayStatus()
{
	std::cout << "HP: " << hp << "/" << maxhp;
	std::cout << "\tEXP: " << exp << "/" << maxexp << "\n";
	std::cout << "STR: " << str << "\tDEF: "<< def << "\tSTA: " << sta << "\n";
	std::cout << "Inventory:\n";
	for (std::string i : inventory)
	{
		std::cout << i << "\t";
	}
	std::cout << "\n";
}
