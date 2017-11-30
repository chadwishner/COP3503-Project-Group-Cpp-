#include "game_engine.hpp"

GameEngine::GameEngine(Player * p, std::queue<Room *> * r) : player(p), rooms(r)
{}

void GameEngine::battle(Monster * m)
{
	std::cout << "A wild " << m->getName() << " attacks!\n";
	while (m->getHP() > 0)
	{
		p->attack(m);
		if (m->getHP() > 0) m->attack(p);
	}
}

void GameEngine::go()
{
	if (rooms->empty() == false)
	{
		roomLoop();
	}
}

void GameEngine::roomLoop()
{
	Room * r = rooms->pop();
	std::cout << r->getMessage();
	int input = 0;
	while (true) // Does this work as a loop condition? Should it be something else?
	{
		int choices = r->getChoices->size();
		for (int i = 0; i < choices; i++)
		{
			std::cout << i + 1 << ". " << r->getChoices()->at(i) << "\n";
		}
		std::cout << choices << ". Check your status\n";
		std::cout << "\nWhat will you do? ";
		std::cin >> input;
		switch(input)
		{
			case 1:
				std::cout << r->getFlavorText();
				break;
			case 2:
				battle(r->getMonster());
				break;
			case 3: // Come back to this. Will get complicated.
				if (r->isComplete())
				{
					std::cout << "You already did this.\n";
					break;
				}
				else
				{
					std::string item = r->getChallenge()->go();
					std::cout << "You got a " << item << "!\n";
					if (item == "key")
					{
						std::cout << "Before you can put it in your inventory, the key flies to the door, unlocks it, and disappears.";
						r->setComplete();
					}
					else
					{
						std::cout << "It flies to the door, jams itself into the keyhole, and unlocks it somehow.\n";
						std::cout << "Then it flies back to you and goes into your inventory.\n";
						//Code to add the item to the inventory
					}
				}
				break;
			case 4:
				if (r->isComplete) go();
				else std::cout << "Try as you might, you cannot open the door, for it is locked. You'll have to find a key.\n";
				break;
			case 5:
				p->displayStatus();
				break;
		}
	}
}
