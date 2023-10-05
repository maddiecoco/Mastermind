// Project 1 for EECE2560
//
//Collaborators: Madeline Coco, Neha Joby
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "code.h"
#include "mastermind.h"

using namespace std;

// Main function: allows user (codebreaker) to play Mastermind against computer (codemaker).
int main() {
    srand(time(0));

    Mastermind mastermind;
    mastermind.playGame();
}