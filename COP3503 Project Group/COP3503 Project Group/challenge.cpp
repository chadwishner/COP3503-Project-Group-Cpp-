//
//  challenge.cpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "challenge.hpp"

//how do we deal with item, this is not correct
string challenge::go(item){
	srand(time(NULL));
	
	int challenge = rand() % 3 + 1;
	
	switch (challenge) {
		case 1:
			walkChallenge(item);
			break;
		case 2:
			quizChallenge(item);
			break;
		case 3:
			battleChallenge(item);
			break;
		default:
			break;
	}
	
	return item;
}


void walkChallenge(string item){
	srand(time(NULL));
	
	int xPosOrNeg = rand() % 2 + 1;
	int yPosOrNeg = rand() % 2 + 1;
	
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
	int playerChoice = 0;
	while (itemXcor != playerXcor && itemYcor != playerYcor){
		int distance = sqrt(pow(itemXcor-playerXcor, 2) + pow(itemYcor-playerYcor, 2));
		std::cout << "You are " << distance << "units away from the item" << endl;
		do {
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
			} else {
				cout << "That is not an acceptable choice, Tsk Tsk, Please Choose 1,2,3, or 4" << endl;
			}
		} while (playerChoice != 1 || playerChoice != 2 || playerChoice != 3 || playerChoice != 4);
		
		playerChoice = 0;
	}
	std::cout << "You have reached the item!\n";
	std::cout << "It is " << item << "\n";
}
