//
//  entity.cpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#include "entity.hpp"
#include <cstdlib.h>

Entity::Entity(int h, int mh, int s, int d, int a) : hp(h), maxhp(mh), str(s), def(d), sta(a)
{}

int Entity::getHP()
{
	return hp;
}

int Entity::getStr()
{
	return str;
}

int Entity::getDef()
{
	return def;
}

int Entity::getSta()
{
	return sta;
}

void Entity::takeDamage(int d)
{
	hp -= d;
	if (hp <= 0)
	{
		die();
	}
}

void Entity::attack(Entity e)
{
	int damage = str - e->getDef();
	int chance = rand() % 100 + 1;
	if (chance > 90) std::cout << "Your attack missed!\n";
	else
	{
		if (chance < 10) damage = ceil(damage * 1.2);
		e->takeDamage(damage);
	}
}
