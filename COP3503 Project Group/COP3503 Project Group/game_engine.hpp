//  game_engine.hpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#ifndef game_engine_hpp
#define game_engine_hpp

#include "player.hpp"
#include "room.hpp"
#include <queue>

class GameEngine{
	private:        Player * player;
                    std::queue<Room *> * rooms;
                    void battle(Monster * m);
		            void roomLoop();

	public:         GameEngine(Player * p, std::queue<Room *> * r);
                    void go();
};

#endif /* game_engine_hpp */
