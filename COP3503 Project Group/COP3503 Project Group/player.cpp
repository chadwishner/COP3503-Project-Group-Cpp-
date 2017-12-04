//  player.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.hpp"

Player::Player(std::string n) : Entity(20, 20, 20, 10, 10, 0, 30, n), hp(20), maxhp(20), str(10), def(10), sta(10), exp(0), level(1), maxexp(30), name(n){
    for (int i = 0; i < 5; i++) {
        inventory[i] = "None";
    }
}

void Player::levelUp(){
	level++;
	
    std::cout << "You leveled up! You are now level " << level << "!\n";
	srand(time(NULL));
	int mhpboost = (rand() % 7 + 3);
	maxhp += mhpboost;
	
    std::cout << "Your maximum HP increased by " << mhpboost << "!\n";
	hp = maxhp;
	int strboost = (rand() % 3 + 1);
	str += strboost;
	
    std::cout << "Your strength increased by " << strboost << "!\n";
	int defboost = (rand() % 3 + 1);
	def += defboost;
	
    std::cout << "Your defense increased by " << defboost << "!\n";
	int staboost = (rand() % 3 + 1);
	sta += staboost;
	
    std::cout << "Your stamina increased by " << staboost << "!\n\n";
	exp = maxexp - exp;
	maxexp += 10;
}

int Player::die(){
	std::cout << "Alas, brave warrior, you are slain! Expect another semester of COP 3502 in your future.\n";
	std::cout << "Your stats were:\n";
	displayStatus();
	exit(0);
	return 0;
}

std::string Player::getType(){
	return "Player"; // Necessary for certain Entity functions.
}

void Player::heal(int h){
	hp += h;
	if (hp > maxhp) hp = maxhp;
}

void Player::gainExp(int e){
	exp += e;
	if (exp >= maxexp) levelUp();
}

std::string * Player::getInv(){
	return inventory;
}
