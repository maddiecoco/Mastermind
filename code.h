
#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Code class: constructed with parameters n and m, and a secret code is initialized with
// n digits each in the range [0, m-1].
class Code {

    // Public member function
public:
    // Constructor
    Code(int n, int m);
    void initializeCode();
    void setSequence(std::vector<int> vec);
    int checkCorrect(Code& guess);
    vector<int> getSequence();
    int checkIncorrect(Code& guess);
    void display();
    //Private data members
private:
    int _length;
    int _range;
    std::vector<int> sequence;
};

// Code constructor to initialize the code object with n random digits in the range [0, m-1]
Code::Code(int n, int m) {
    _length = n;
    _range = m;
}

// initializeCode function: used to reset the secret code randomly
void Code::initializeCode() {
    sequence.resize(_length);
    for (int & i : sequence)
    {
        i = rand() % _range;
    }

    for (int & i : sequence)
    {
        i = rand() % (sequence.size());
    }
}

void Code::setSequence(vector<int> vec)
// Function to set sequence/guess from a code object
{
    for (int element : vec)
    {
        sequence.push_back(element);
    }

}

vector<int> Code::getSequence()
// Function to return sequence from a code object
{
    return sequence;
}

// checkCorrect function: used to check the number of correct digits in the correct location
int Code::checkCorrect(Code& guess) {
    int count = 0;
    for (int i = 0; i < sequence.size(); i++)
        if (sequence[i] == guess.sequence[i])
            count++;
    return count;
}

// checkIncorrect function: used to check the number of correct digits in the incorrect location
int Code::checkIncorrect(Code& guess) {
    int count = 0;

    // Loop through the secret code
    for (int secret_i = 0; secret_i < _length; secret_i++)
    { 
        // Loop through the guess code at every index of the secret code
        for (int guess_i = 0; guess_i < _length; guess_i++)
        { 
            // Check so correct ints at correct location aren't being counted
            if (sequence[secret_i] == guess.sequence[secret_i])
            {
                break;
            }
            else if (sequence[secret_i] == guess.sequence[guess_i])
            {
                count += 1;
                // Set counted values out of range, to prevent double counting
                guess.sequence[guess_i] = _range;
                break;
            }
        } // end guess code for loop
    }
    return count;
}

// display function to display the code sequence
void Code::display() {
    for(const int & i : sequence)
        std::cout << i << " ";
    std::cout << std::endl;
}

#endif
