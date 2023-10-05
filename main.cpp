// Project 1 for EECE2560
//
//Collaborators: Madeline Coco, Neha Joby
//
// The main function for part a of project 1. 

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "code.h"

using namespace std;

// Main function: initializes a secret code and compares it against 3 sample 
// guesses, printing the results. The secret code is also printed.
int main() {

    Code secretCode(5, 7); // Initialize secret code with n=5, m=7
    secretCode.initializeCode(); 

    cout << "SECRET CODE:" << endl;
    secretCode.display(); // Display the secret code

    // Three sample guesses saved as vectors, and then used as the input
    // for the setSequence function 
    Code guess1(5, 7);
    vector<int> first_try = {5, 0, 3, 2, 6};
    guess1.setSequence(first_try);
    
    Code guess2(5, 7);
    vector<int> second_try = {2, 1, 2, 2, 2};
    guess2.setSequence(second_try);

    Code guess3(5, 7);
    vector<int> third_try = {1, 3, 3, 4, 5};
    guess3.setSequence(third_try);

    // Displaying results of calling checkCorrect and checkIncorrect for 3 
    // sample guess codes
    cout << "Guess 1: Correct: " << secretCode.checkCorrect(guess1);
    cout <<  ", Incorrect: " << secretCode.checkIncorrect(guess1) << endl;
    cout << "Guess 2: Correct: " << secretCode.checkCorrect(guess2);
    cout << ", Incorrect: " << secretCode.checkIncorrect(guess2) << endl;
    cout << "Guess 3: Correct: " << secretCode.checkCorrect(guess3);
    cout << ", Incorrect: " << secretCode.checkIncorrect(guess3) << endl;

    return 0;
}


