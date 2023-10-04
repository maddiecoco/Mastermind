// PART B
// Last edited: Neha - 10/3 1:30PM


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

        void setResponses(const Code& guess, const Code& secret);
        int getCorrect();
        int getIncorrect();

        // Operator overloading: for comparison and output
        friend bool operator==(const Response& lhs, const Response& rhs) const;
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

// Sets response object with the values for the correct and incorrect numbers in the guess
void Response::setResponses(const Code& guess,const Code& secret)
{
    int correct = secret.checkCorrect(guess);
    int incorrect = secret.checkIncorrect(guess);
}

int Response::getCorrect()
{
    return correct;
}

int Response::getIncorrect()
{
    return incorrect;
}

bool operator==(const Response& lhs, const Response& rhs)
{
    return lhs.getCorrect() == rhs.getCorrect() && lhs.getIncorrect() == rhs.getIncorrect();
}

ostream& operator<<(ostream& ostr, const Response& attempt)
{
    ostr << "Correct: " << attempt.correct << "\nIncorrect: " << attempt.incorrect;
    return ostr;
}



#endif //PROJECT_1_RESPONSE_H
