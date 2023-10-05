// Project 1 for EECE2560
//Part B
//
//Collaborators: Madeline Coco, Neha Joby
//This file contains the Response class.

#ifndef RESPONSE_H
#define RESPONSE_H
#include <iostream>
#include "code.h"

using namespace std;

class Response {
    // Public member functions
    public:
        // Default constructor: initializes both correct and incorrect to 0
        Response() : correct(0), incorrect(0) {};

        // Parameter constructor: sets initial values for correct and incorrect
        Response(int c, int i);

        void setResponses(Code& guess, Code& secret);
        const int getCorrect();
        const int getIncorrect();

        // Operator overloading: for comparison and output
        friend bool operator==(const Response& lhs, const Response& rhs);
        friend ostream& operator<<(ostream& ostr, const Response& attempt);

    // Private member functions
    private:
        // Number of correct and incorrect guesses
        int correct, incorrect;
};


// Constructor
Response::Response(int c, int i) {
    correct = c;
    incorrect = i;
}

// Sets response object with the values for the correct and incorrect digits
// by comparing the guess code to the secret code
void Response::setResponses(Code& guess, Code& secret)
{
    correct = secret.checkCorrect(guess);
    incorrect = secret.checkIncorrect(guess);
}

// Gets the private data member for the number of correct digits
const int Response::getCorrect()
{
    return correct;
}

// Gets the private data member for the number of incorrect digits
const int Response::getIncorrect()
{
    return incorrect;
}

// Overloaded == operator compares 2 response objects and returns 
// true if they are equal
bool operator==(const Response& lhs, const Response& rhs)
{
    return lhs.correct == rhs.correct && lhs.incorrect == rhs.incorrect;
}

// Overloaded operator << that prints a response, displaying it's 
// correct and incorrect values
ostream& operator<<(ostream& ostr, const Response& rhs)
{
    ostr << "Correct: " << rhs.correct << "\nIncorrect: " << rhs.incorrect;
    return ostr;
}



#endif //PROJECT_1_RESPONSE_H
