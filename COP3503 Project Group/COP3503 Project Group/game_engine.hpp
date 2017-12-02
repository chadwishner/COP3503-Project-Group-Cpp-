#ifndef game_engine_hpp
#define game_engine_hpp

#include "player.hpp"
#include "room.hpp"
#include <queue>

class GameEngine
{
	private:
		Player * player;
		std::queue<Room *> * rooms;
		void battle(Monster * m);

	public:
		GameEngine(Player * p, std::queue<Room *> * r);
		void go();
};

#endif /* game_engine_hpp */
