//  main.cpp
//  COP3503 Project Group

//  Copyright © 2017 Group 35. All rights reserved.

#include <iostream>
#include "game_engine.hpp"
#include "player.hpp"

int main(int argc, const char * argv[]) {
   
    std::cout << "Welcome to a mystical adventure through COP 3502. Your programming assignment has a nasty bug in it, and it is up to you to reach the dungeon and fix it before the submission deadline. If you fail this assignment, you can kiss your grade goodbye. There will be many perils on your quest. Many will obstruct your path to an A.\n\n";
  
    std::cout << "O terminal soldier, what is your name?\n";
   
    std::string name = "";
    std::cin >> name;
   
    Player * p = new Player(name);
    std::queue<Room *> * roomList = new std::queue<Room *>();

//  Room 1 : NPB 1001
    
    challenge c = challenge();
   
    std::string message = "It is 7:25 AM, and you're wishing you could be anywhere but here. Your mind can do nothing but wander, try as you might to focus.\nYes - you're in NPB 1001.\n";
   
    std::string flavorText = "Since your mind is already wandering, this is not difficult to do. The ten other people in the room are all buried in their laptop screens, checking Reddit, Canvas, or what have you in desperate attempts to stay awake for the 25th hour in a row. As entertaining a challenge as that project was, it took a toll on the students. You feel like nobody would notice if you left.\n";
  
    std::vector<std::string> choices = {
	"See what everyone else is up to.",
	"Ask the professor a question.",
	"Look for a way to unlock the door.",
	"Try and sneak out."
    };
   
    Monster m = Monster(5, 5, 11, 8, 10, 30, "DR. KAVALAN");
    Room * r = new Room(&c, &m, message, flavorText, choices);
    roomList -> push(r);
    
//  Room 2 : Bookstore
    
    c = challenge(2, "key");
    message = "After that experience, you decide to pay a visit the campus bookstore. Yes, the prices here are exorbitantly high, but at this point, you might be able to get more out of a textbook than a 7:25 lecture. Perhaps you will be able to find a clue here to help you debug your program.";
    flavorText = "You pick up the nearest copy of C++ Primer, Fifth Edition and begin to flip through the pages. This would be a convenient resource, if not for the fact that it's nearly 1000 pages long. Stack Overflow would be much more helpful here.";
    choices = {
        "Open up a C++ textbook.",
        "Wander the shelves.",
        "Talk to an employee.",
        "Leave the bookstore."
    };
    m = Monster(8, 8, 13, 10, 15, 45, "overpriced textbook");
    r = new Room(&c, &m, message, flavorText, choices);
    roomList -> push(r);
    
//  Room 3 : Stadium goes here
    

    
//  Room 4 : Chick fil a HUB
   
    c = challenge(1, "key");
    
    message = "Heed this warning young student. Many juniors-by-credits have attempted this quest and met their ultimate demise. Do you have the grit to engage in battle with such a terrifying opponent? As you enter this faintly familiar establishment, you must decide your course of action.";
    
    flavorText = "You can hear faint 2015 top ten hits in the distance. The aroma of deep fried potatoes and chicken fill your nostrils. You hear “cha-ching” as flex bucks vanish into the meal plan abyss. The doors lock all around you. Where ever could you be? That’s right. Broward Chick-Fil-A. As the chills creep up your spine, you feel a being staring from behind. As you turn around slowly, you see it. The Chick-Fil-A cow. He bellows “EAT MORE CHICKEN” as he charges you in attack mode. As he approaches, you spot a deep fried key shimmering at the cash register. Maybe, just maybe, you could evade the cow, grab it, and make your escape.";
    
    choices = {
        "Look around.",
        "Engage the Chick-Fil-A Cow.",
        "Dodge the cow, dash for the key.",
        "Make your way over to the exit, unlock the door, and continue your journey."
    };
    m = Monster(0, 0, 0, 0, 0, 0, "Chick-Fil-A Cow");
    r = new Room(&c, &m, message, flavorText, choices);
    roomList -> push(r);
    
//Room 5 : Carleton
   
    c = challenge(2, "key");
    message = "It is 8:00 PM, the day you've waiting for, the day you've dreaded: Exam Day.\nTheres a wisper in your ear \"you will fail\" it tells you.\nNo - You will succeed.\n";
    flavorText = "Stress builds, you question yourself, \"Did I study enough\". Did you?\n"; // Insert room-entry message here.
    
     choices = {
        "See how everyone else answered question number 5 part c", // Insert "examine" choice here.
        "Ask the proctor a question", // Insert "battle" choice here.
        "Answer the final question", // Insert "challenge" choice here.
        "Take the L and leave" // Insert "leave" choice here.
    };
    m = Monster(10, 10, 15, 12, 15, 20, "The Proctor"); // Insert, in this order, the HP, max HP, STR, DEF, STA, EXP yield upon death, name.
    r = new Room(&c, &m, message, flavorText, choices);
    roomList -> push(r);
    
    
//Room 6 : Broward Dining goes here
    
    
//Room 7 : Turlington
    c = challenge(1, "key");
    
    message = "As you walk along the path, you near your destination. You pass sign after sign telling you to turn back. As you get closer, the faint sounds of voices get louder and louder. Soon, you hear a sea of foot traffic. You can hear clubs recruiting and fundraising from a mile away. Your eyes widen as your realize where you are. You’re standing in the center of Turlington.";
    
    flavorText = "As you scan the landscape, you spot a few things through the crowd. You see a science library, a glowing potato looking monstrosity, and a gator growl fundraiser verbally assaulting other students. You stop to notice a muscular-legged silhouette. You see a hand shoot up in the shape of a peace sign. There’s no mistake, it’s Dennis, The Peace Guy. His insanely toned quads propel him towards you.";
    
    choices = {
        "Look around.",
        "Engage Dennis in battle.",
        "Dodge Dennis, dash for the glowing potato.",
        "Open the door to the Computer Science and Engineering Building."
    };
    m = Monster(0, 0, 0, 0, 0, 0, "Dennis, The Peace Guy");
    r = new Room(&c, &m, message, flavorText, choices);
    roomList -> push(r);
    
//Room 8 : Dungeon
    
    c = challenge();

    message = "It has been a long and tough journey, but you have finally made it to the dungeon. There is only one thing between you and your A now: the dreaded segmentation fault. It mocks you with its vague and unhelpful error message. What has caused it? What can fix it? The compiler refuses to say. Only you can put a stop to this error's wicked ways. The time has come to do battle.";

    flavorText = "There is not a soul in sight. The stage is set for your final showdown. No obstructions, no distractions - the time is now.";

    choices = {
	"Survey the territory.",
	"Confront the almighty segfault.",
	"Scrounge for a Gatorade.",
	"Onward!",
    };

    m = Monster(0, 0, 0, 0, 0, 0, "SEGFAULT");

    r = new Room(&c, &m, message, flavorText, choices);
    roomList -> push(r);
    
    GameEngine * g = new GameEngine(p, roomList);
    g -> go();

    std::cout << "You've done it, " << p->getName() << ". You have defeated the last thing standing between your assignment and a no-output g++ -Wall command. And just in time, too - the assignment is due in five minutes. You take a moment to bask in the satisfaction of an assured A on both the assignment and the class.\n";
    std::cout << "As you click the \"Submit\" button on Canvas, something nags at you. You can't quite put your finger on it, but right as the submission deadline rolls by, it dawns on you.\n\n";
    std::cout << "You forgot to test it.\n";

    delete p;
    delete roomList;
    delete g;
    return 0;
}
