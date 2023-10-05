// Project 1 for EECE2560
//
//Collaborators: Madeline Coco, Neha Joby
//
//Main function for part b of project 1. Allows the user to fully
// play through the mastermind game.

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "code.h"
#include "mastermind.h"

using namespace std;

// Main function: allows user (codebreaker) to play Mastermind against 
// computer (codemaker).
int main() {

    Mastermind mastermind;
    mastermind.playGame();
}