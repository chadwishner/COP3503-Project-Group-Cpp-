//  entity.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include "entity.hpp"
#include <cstdlib>
#include <ctime>

Entity::Entity(int h, int mh, int s, int d, int a, int e, int me, int level, std::string n) : hp(h), maxhp(mh), str(s), def(d), sta(a), exp(e), level(level), maxexp(me), name(n){
    for (int i = 0; i < 5; i++) {
        inventory[i] = "None";
    }
}

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
		return die(); // This starts a long daisy-chain of return statements before the yielded EXP finally makes its way to the player object.
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
	
    // Sometimes the attack should miss or crit to make things interesting.
    if (chance > 90) std::cout << "The attack missed!\n";
	else {
		if (chance < 10) {
			damage = ceil(damage * 1.2);
			std::cout << "A critical hit! ";
		}
		std::cout << e->getName() << " takes " << damage << " damage!\n\n";
		
        int spoils = e->takeDamage(damage);
		return spoils; // Here's the continuation of that daisy-chain.
	}
	return 0;
}

void Entity::displayStatus(){
    std::cout << "HP: " << hp << "/" << maxhp;
    std::cout << "\tEXP: " << exp << "/" << maxexp << "\n";
    std::cout << "STR: " << str << "\tDEF: "<< def << "\tSTA: " << sta << "\n";
    std::cout << "\nInventory:\n";
    for (std::string i : inventory){
        std::cout << i << "\t";
    }
    std::cout << "\n\n";
}

void Entity::levelUp(){
    level++;
    
    std::cout << "You leveled up! You are now level " << level << "!\n";
    srand(time(NULL));
    int mhpboost = (rand() % 4 + 2);
    maxhp += mhpboost;
    
    std::cout << "Your maximum HP increased by " << mhpboost << "!\n";
    hp = maxhp;
    int strboost = (rand() % 4 + 2);
    str += strboost;
    
    std::cout << "Your strength increased by " << strboost << "!\n";
    int defboost = (rand() % 4 + 2);
    def += defboost;
    
    std::cout << "Your defense increased by " << defboost << "!\n";
    int staboost = (rand() % 4 + 2);
    sta += staboost;
    
    std::cout << "Your stamina increased by " << staboost << "!\n\n";
    exp = exp - maxexp;
    maxexp += 10;
}

void Entity::gainExp(int e){
    exp += e;
    if (exp >= maxexp) levelUp();
}
