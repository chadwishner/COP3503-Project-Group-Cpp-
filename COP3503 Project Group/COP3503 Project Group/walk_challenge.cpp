//  walk_challenge.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

/*Created walk challenge as a function call, don't see why we need it as an object, could just call 1 of 3 challenge functions in challenge class (challenge class can handle what the item is, and 3 fucntions only have to pass in item and return item when goal is met)
*/

#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "walk_challenge.hpp"

void walkChallenge:: go(){
	
	std::string item;
	srand(time(NULL));
	
	int xPosOrNeg = rand() % 2 + 1;
	int yPosOrNeg = rand() % 10 + 1;
	
	int itemXcor = 5 + (rand() * (int)(10 - 5) / 10);
	int itemYcor = 5 + (rand() * (int)(10 - 5) / 10);
	
	int playerXcor = 0;
	int playerYcor = 0;
	
	if (xPosOrNeg == 2){
		itemXcor = -itemXcor;
	}
	if (yPosOrNeg == 2){
		itemYcor = -itemYcor;
	}
	int playerChoice;
	while (itemXcor != playerXcor && itemXcor != playerYcor){
		int distance = sqrt(pow(itemXcor-playerXcor, 2) + pow(itemYcor-playerYcor, 2));
		std::cout << "You are " << distance << "units away from the item" << endl;
		while (playerChoice != 1, playerChoice != 2, playerChoice != 3, playerChoice != 4){
			std::cout << "Please select which direction you would like to move:\n1. Left\n2. Right\n3. Forward\n4. Backwards\n";
			std::cin >> playerChoice;
			
			if (playerChoice == 1){
				playerXcor--;
			} else if (playerChoice == 2){
				playerXcor++;
			} else if (playerChoice == 3){
				playerYcor++;
			} else if (playerChoice == 4){
				playerYcor--;
			}
		}
	}
	std::cout << "You have reached the item!\n";
	std::cout << "It is " << item << "\n";
	
	//must return string
	return item;
}
