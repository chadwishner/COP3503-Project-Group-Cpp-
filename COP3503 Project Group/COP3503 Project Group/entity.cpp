//  entity.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include "entity.hpp"
#include <cstdlib>
#include <ctime>

Entity::Entity(int h, int mh, int s, int d, int a, int e, std::string n) : hp(h), maxhp(mh), str(s), def(d), sta(a), exp(e), name(n){}

int Entity::getHP(){
	return hp;
}

int Entity::getStr(){
	return str;
}

int Entity::getDef(){
	return def;
}

int Entity::getSta(){
	return sta;
}

std::string Entity::getName(){
	return name;
}

int Entity::takeDamage(int d){
	hp -= d;
	if (hp <= 0){
		return die();
	} else return 0;
}

int Entity::attack(Entity * e){
	if (getType() == "Player"){
		std::cout << "You attack " << e->getName() << "!\n";
	} else{
		std::cout << getName() << " attacks!\n";
	}
	
    int damage = str - e->getDef();
	
    if (damage < 0) damage = 0;
	
    srand(time(NULL));
	int chance = rand() % 100 + 1;
	
    if (chance > 90) std::cout << "The attack missed!\n";
	else {
		if (chance < 10) {
			damage = ceil(damage * 1.2);
			std::cout << "A critical hit! ";
		}
		std::cout << e->getName() << " takes " << damage << " damage!\n\n";
		
        int spoils = e->takeDamage(damage);
		return spoils;
	}
	return 0;
}
