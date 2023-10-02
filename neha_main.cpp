// Part A
// Code class with the required functions and a main function to test the functionality

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Code class: constructed with parameters n and m, and a secret code is initialized with
// n digits each in the range [0, m-1].
class Code {
    std::vector<int> sequence;

// Public member function
public:
    // Constructor
    Code(int n, int m);
    void initializeCode();
    int checkCorrect(const Code& guess) const;
    int checkIncorrect(const Code& guess) const;
    void display() const;
};

// Code constructor to initialize the code object with n random digits in the range [0, m-1]
Code::Code(int n, int m) {
    sequence.resize(n);
    for (int & i : sequence)
        i = rand() % m;
}

// initializeCode function: used to reset the secret code randomly
void Code::initializeCode() {
    for (int & i : sequence)
        i = rand() % (sequence.size());
}

// checkCorrect function: used to check the number of correct digits in the correct location
int Code::checkCorrect(const Code& guess) const {
    int count = 0;
    for (int i = 0; i < sequence.size(); i++)
        if (sequence[i] == guess.sequence[i])
            count++;
    return count;
}

// checkIncorrect function: used to check the number of correct digits in the incorrect location
int Code::checkIncorrect(const Code& guess) const {
    int count = 0;
    std::vector<bool> counted(sequence.size(), false);
    for (int i = 0; i < sequence.size(); i++) {
        for (int j = 0; j < sequence.size(); j++) {
            if (i != j && !counted[j] && sequence[j] == guess.sequence[i]) {
                counted[j] = true;
                count++;
                break;
            }
        }
    }
    return count;
}

// display function to display the code sequence
void Code::display() const {
    for(const int & i : sequence)
        std::cout << i << " ";
    std::cout << std::endl;
}

// Main function:  initializes a secret code and compares it against three sample guesses, printing the results.
// The secret code is also printed for reference.
int main() {
    srand(time(0));

    Code secretCode(5, 7); // Initialize secret code with n=5, m=7
    secretCode.display(); // Display the secret code

    Code guess1({5, 0, 3, 2, 6});
    Code guess2({2, 1, 2, 2, 2});
    Code guess3({1, 3, 3, 4, 5});

    // Displaying results of calling checkCorrect and checkIncorrect for three sample guess codes
    std::cout << "Guess 1: Correct: " << secretCode.checkCorrect(guess1) << ", Incorrect: " << secretCode.checkIncorrect(guess1) << std::endl;
    std::cout << "Guess 2: Correct: " << secretCode.checkCorrect(guess2) << ", Incorrect: " << secretCode.checkIncorrect(guess2) << std::endl;
    std::cout << "Guess 3: Correct: " << secretCode.checkCorrect(guess3) << ", Incorrect: " << secretCode.checkIncorrect(guess3) << std::endl;

    return 0;
}
