//  game_engine.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include "game_engine.hpp"
#include "room.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "challenge.hpp"

GameEngine::GameEngine(Player * p, std::queue<Room *> * r) : player(p), rooms(r){}

void GameEngine::battle(Monster * m){
	std::cout << "A wild " << m->getName() << " attacks!\n\n";
    std::cout << "Monster HP = " << m->getHP() <<"\n";
    int choice = 0;
	
    while (m->getHP() > 0){
		std::cout << "What will you do?\n";
		std::cout << "1. Attack\n";
		std::cout << "2. Chug a Gatorade\n";
		std::cout << "3. View your status\n";
		std::cout << "4. Flee\n\n";
		std::cin >> choice;
		if (choice == 1){
			int spoils = player -> attack(m);
			if (spoils != 0) player -> gainExp(spoils);
		} else if (choice == 2){
			bool hasDrink = false;
			int drinkIndex = 0;
			for (int i = 0; i < 5; i++){
				if (player -> getInv()[i] == "Gatorade"){
					hasDrink = true;
					drinkIndex = i;
					break;
				}
			}
			if (hasDrink){
				std::cout << "You vigorously drink a Gatorade and regain 20 health!\n\n";
				player -> heal(20);
				player -> getInv()[drinkIndex] = "None";
			} else{
				std::cout << "You don't have any Gatorade to chug!\n\n";
			}
		} else if (choice == 3) player->displayStatus();
		else if (choice == 4){
			std::cout << "You flee the fight, tail between your legs. " << m->getName() << " lives to see another day.\n\n";
			return;
		}
		if (m -> getHP() > 0) m->attack(player);
	}
}

void GameEngine::go(){
	if (rooms -> empty() == false){
		roomLoop();
	}
}

void GameEngine::roomLoop(){
	Room * r = rooms -> front();
	rooms -> pop();
	
	std::cout << r -> getMessage();
	int input = 0;
	
	while (true){ // Does this work as a loop condition? Should it be something else?
		int choices = r -> getChoices().size();
		
		for (int i = 0; i < choices; i++){
			std::cout << i + 1 << ". " << r -> getChoices().at(i) << "\n";
		}
		
		std::cout << choices << ". Check your status\n";
		std::cout << "\nWhat will you do? ";
		std::cin >> input;
		
		if (input == 1) std::cout << r->getFlavorText();
		else if (input == 2) battle(r->getMonster());
		else if (input == 3){
			if (rooms->empty() == false && r->isComplete()) std::cout << "You already did this.\n";
			else{
				std::string item = r->getChallenge()->go();
				std::cout << "You got a " << item << "!\n";
				if (item == "key" && rooms->empty() == false){
					std::cout << "Before you can put it in your inventory, the key flies to the door, unlocks it, and disappears.";
					r->setComplete();
				} else if (item != "key" && rooms->empty() == false){
					std::cout << "It flies to the door, jams itself into the keyhole, and unlocks it somehow.\n";
					int openIndex = -1;
					for (int i = 0; i < 5; i++){
						if (player -> getInv()[i] == "None"){
							openIndex = i;
							break;
						}
					}
					if (openIndex == -1){
						std::cout << "And then, equally mysteriously, it disintegrates.\n";
					}
					else{
						std::cout << "Then it flies back to you and goes into your inventory.\n";
						player -> getInv()[openIndex] = item;
					}
                    r->setComplete();
				}
				else
				{
					int openIndex = -1;
					for (int i = 0; i < 5; i++)
					{
						if (player->getInv()[i] == "None")
						{
							openIndex = i;
							break;
						}
					}
					if (openIndex != -1)
					{
						std::cout << "You put it in your inventory.\n";
						player->getInv()[openIndex] = item;
					}
				}
			}
		} else if (input == 4){
			if (rooms->empty() && r->getMonster()->getHP() <= 0)
			{
				r->setComplete();
				return;
			}
			if (r->isComplete())
			{
				go();
				return;
			}
			else std::cout << "Try as you might, you cannot open the door, for it is locked. You'll have to find a key.\n";
		} else if (input == 5) player->displayStatus();
	}
}
