//
//  entity.hpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#ifndef entity_hpp
#define entity_hpp

#include <stdio.h>

class Entity
{
	protected:
		int hp;
		int maxhp;
		int str;
		int def;
		int sta;
		int exp;
		virtual int die();

	public:
		Entity(int h, mh, s, d, a);
		int getHP();
		int getStr();
		int getDef();
		int getSta();
		void takeDamage(int d);
		void attack(Entity e);
};
#endif /* entity_hpp */
