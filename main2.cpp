// Project 1 for EECE2560
//
//Collaborators: Madeline Coco, Neha Joby
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "code.h"

using namespace std;

// Main function:  initializes a secret code and compares it against three sample guesses, printing the results.
// The secret code is also printed for reference.
int main() {
    srand(time(0));

    Code secretCode(5, 7); // Initialize secret code with n=5, m=7
    secretCode.initializeCode(); 

    secretCode.display(); // Display the secret code

    Code guess1(5, 7);
    vector<int> first_try = {5, 0, 3, 2, 6};
    guess1.setSequence(first_try);
    
    Code guess2(5, 7);
    vector<int> second_try = {2, 1, 2, 2, 2};
    guess2.setSequence(second_try);

    Code guess3(5, 7);
    vector<int> third_try = {1, 3, 3, 4, 5};
    guess3.setSequence(third_try);

    // Displaying results of calling checkCorrect and checkIncorrect for three sample guess codes
    std::cout << "Guess 1: Correct: " << secretCode.checkCorrect(guess1) << ", Incorrect: " << secretCode.checkIncorrect(guess1) << std::endl;
    std::cout << "Guess 2: Correct: " << secretCode.checkCorrect(guess2) << ", Incorrect: " << secretCode.checkIncorrect(guess2) << std::endl;
    std::cout << "Guess 3: Correct: " << secretCode.checkCorrect(guess3) << ", Incorrect: " << secretCode.checkIncorrect(guess3) << std::endl;

    return 0;
}
