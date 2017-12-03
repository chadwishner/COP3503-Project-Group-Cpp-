//  challenge.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "challenge.hpp"

challenge::challenge(){
	srand(time(NULL)); // random pre-definition
	challengeType = rand() % 2 + 1; // randomizes item if an empty constructor is called
	
	int itemNum = rand() % 2 + 1;
	if (itemNum == 2){
		item = "Gatorade";
	} else {
		item = "key";
	}
}

challenge:: challenge(int challengeType, string item){ // challenge constructor
	this -> challengeType = challengeType;
	this -> item = item;
}

string challenge::go(){
	
	switch (challengeType) { // defines which challenge function to call
		case 1:
			walkChallenge();
			break;
		case 2:
			quizChallenge();
			break;
		default:
			break;
	}
	
	return item;
}


void challenge::walkChallenge(){
	srand(time(NULL));
	
	int xPosOrNeg = rand() % 2 + 1; // randomizes a position to put the item in a 2 dimensional surface
	int yPosOrNeg = rand() % 2 + 1;
	
	int itemXcor = rand() % 10 + 5;
	int itemYcor = rand() % 10 + 5;
	
	int playerXcor = 0;
	int playerYcor = 0;
	
	if (xPosOrNeg == 2){
		itemXcor = -itemXcor;
	}
	if (yPosOrNeg == 2){
		itemYcor = -itemYcor;
	}
	int playerChoice = 0;
	while (itemXcor != playerXcor || itemYcor != playerYcor){
		int distance = sqrt(pow(itemXcor-playerXcor, 2) + pow(itemYcor-playerYcor, 2));
		std::cout << "You are " << distance << " units away from the item\n"; //prints distance from item so player can move accordingly.
        do {
            playerChoice = 0;
			std::cout << "Please select which direction you would like to move:\n1. Left\n2. Right\n3. Forward\n4. Backwards\n";
			std::cin >> playerChoice;
            
            while(std::cin.fail()){
                std::cout<<"Invalid entry, try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Please select which direction you would like to move:\n1. Left\n2. Right\n3. Forward\n4. Backwards\n";
                std::cin >> playerChoice;
            }
			
			if (playerChoice == 1){
				playerXcor--;
			} else if (playerChoice == 2){
				playerXcor++;
			} else if (playerChoice == 3){
				playerYcor++;
			} else if (playerChoice == 4){  // moves player
				playerYcor--;
			} else {
				cout << "That is not an acceptable choice, tsk tsk. Please choose 1,2,3, or 4\n";
			}
		} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3 && playerChoice != 4);
		
		playerChoice = 0;
	}
	std::cout << "You have reached the item!\n";
}


void challenge::quizChallenge(){
	
	srand(time(NULL));
	
	bool proceed = false;
	int response;
	string responseAccept;
	
	int number = rand() % 9 +1; // quiz challenge with 10 questions
	string questions[] = {"What year was UF established?\n\t1.1905\n\t2.1968\n\t3.1853\n\t4.1492\n",
		"Who is the president of UF?\n\t1.Eliahu Hanavid\n\t2.Kent Fuchs\n\t3.Korpus Kane\n\t4.Isaac Roth\n",
		"What atlethics conference does the university belong to?\n\t1.NCAA\n\t2.PHP\n\t3.SEC\n\t4.MBAA\n",
		"How many stoplights are on the actual campus?\n\t1.4\n\t2.5\n\t3.6\n\t4.3\n",
		"What are the husband and wife mascots' names?\n\t1.Albert and Longtail\n\t2.Longtail and Louis\n\t3.Albert and Alberta\n\t4.Alec and Ashley\n",
		"What is the name of the alumni hall?\n\t1.Grant\n\t2.Warrington\n\t3.Emerson\n\t4.Hume\n",
		"Florida's only undefeated and un-tied regular season was (includes conference championship game):\n\t1.1994\n\t2.1995\n\t3.1996\n\t4.2009\n",
		"The all-time career passing yards leader in Florida history is:\n\t1.Chris Leak\n\t2.Shane Matthews\n\t3.Tim Tebow\n\t4.Rex Grossman\n",
		"What was the earliest college founded at the university (in 1906)?\n\t1.College of Agricultural and Life Sciences\n\t2.College of Engineering\n\t3.College of Liberal Arts\n\t4.College of Medicine.\n",
		"Who is the student union named after? \n\t1.Reitz Ritz\n\t2.P. Carter Reitz\n\t3.John Reitz III\n\t4.J. Wayne Reitz\n"};
	int answers[10] = {3,2,3,2,1,3,2,1,1,4}; // array with answer choices that coorelates to correct answer for array of strings question.
	
	cout << "Welcome to the Quiz Challenge, adventurous student. In order to proceed, you must answer the question correctly. Every time you choose a wrong answer. You will be forced to answer a different qurestion. Do you accept?\n(Enter your answers as numbers)\n\t1.COME AT ME\n\t2.No, I don't. I'm a snowflake.\n"; //
	cin >> response;
    
    while(std::cin.fail()){
        std::cout<<"Invalid entry, try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Do you accept?\n(Enter your answers as numbers)\n\t1.COME AT ME\n\t2.No, I don't. I'm a snowflake.\n";
        std::cin >> response;
    }
    
	if(response == 2){
		cout<<"Too bad. Office hours were cancelled; you have no choice but to face your destiny solo.\n";
	}
	while (!proceed) {
		response = 0;
		cout << questions[number];
		cin >> response;
        
        while(std::cin.fail()){
            std::cout<<"Invalid entry, try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cin >> response;
        }
        
		if (response != answers[number]){ //checks answer with right answer choice
			number = rand() % 9 + 1; // if not correct, randomizes another question
		} else{
			cout<<"Congratulations! On with your education.\n";
			proceed = true; //if correct changes value to get out of loop
		}
	};
}
