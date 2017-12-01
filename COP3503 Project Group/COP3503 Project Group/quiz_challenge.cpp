//
//  quiz_challenge.cpp
//  COP3503 Project Group
//
//  Created by Chad Wishner on 11/5/17.
//  Copyright © 2017 Group 35. All rights reserved.
//
#include "quiz_challenge.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void quizchallenge::test(){
    bool proceed = false;
    int response;
    string responseAccept;
    
    int number = rand() % 9 +1;
    string questions[]={"What Year was UF established?\n\t1.1905\n\t2.1968\n\t3.1853\n\t4.1492",
        "Who is the President of UF?\n\t1.Eliahu Hanavid\n\t2.Kent Fuchs\n\t3.Korpus Kane\n\t4.Isaac Roth",
        "What atlethics conference does the university belong to?\n\t1.NCAA\n\t2.PHP\n\t3.SEC\n\t4.MBAA",
        "How many stoplights are on the actual campus?\n\t1.4\n\t2.5\n\t3.6\n\t4.3",
        "What are the husband and wife mascots names?\n\t1.Albert and Longtail\n\t2.Longtail and Louis\n\t3.Albert and Alberta\n\t4.Alec and Ashley",
        "What is the name of the alumni hall?\n\t1.Grant\n\t2.Warrington\n\t3.Emerson\n\t4.Hume",
        "Florida's only undefeated and un-tied regular season was (includes conference championship game:\n\t1.1994\n\t2.1995\n\t3.1996\n\t4.2009",
        "The all-time career passing yards leader in Florida history is:\n\t1.Chris Leak\n\t2.Shane Matthews\n\t3.Tim Tebow\n\t4.Rex Grossman",
        "What was the earliest college founded at the university (in 1906)?\n\t1.College of Agricultural and Life Sciences\n\t2.College of Engineering\n\t3.College of Liberal Arts\n\t4.College of Medicine.",
        "Who is the student union named after? \n\t1.Reitz Ritz\n\t2.P. Carter Reitz\n\t3.John Reitz III\n\t4.J. Wayne Reitz"};
    int answers[10] = {3,2,3,2,1,3,2,1,1,4};
    
    cout<<"Welcome to the Quiz Challenge adventurous student. In order to proceed you must answer the question correct. Everytime you choose a wrong answer, your grade will be deducted by 10 points.Do you accept?\n(Enter your answers as numbers)\n\t1.Yes I do\n\t2.No, I dont, im a snowflake.";
    cin>>response;
    if(response== 2){
        cout<<"Too Bad,Office Hours were cancelled, you have no choice but to face your destiny solo.\n";
    }
    while (!proceed) {
        response = 0;
        cout<<questions[number];
        cin>>response;
        if (response!= answers[number]){
            //health-1, how do i do this? take in paremeter?
            cout<<"Wrong Answer Try Again; Subtract 10 Health";
        }else{
            cout<<"Congratulations! On with your education.";
            proceed = true;
        }
    };
}
