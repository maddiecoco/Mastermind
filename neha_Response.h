//
// Created by nehae on 10/2/2023.
//

#ifndef PROJECT_1_RESPONSE_H
#define PROJECT_1_RESPONSE_H
#include <iostream>
#include "code.h"

using namespace std;

class Response {

    public:
        Response(int c, int i);
        void setResponses(const Code& guess, const Code& secret);
        void getResponses(const Response& attempt);
        bool operator==(const Response& attempt);
        friend ostream& operator<<(ostream& ostr, const Response& attempt);
    private:
        int correct;
        int incorrect;
};

// Constructor
Response::Response(int c, int i) {
    correct = c;
    incorrect = i;
}

//Sets response object with the values for the correct and incorrect numbers in the guess
void Response::setResponses(const Code& guess,const Code& secret)
{
    int correct = secret.checkCorrect(guess);
    int incorrect = secret.checkIncorrect(guess);
}

bool Response::operator==(const Response& attempt)
{
    return correct == attempt.correct && incorrect == attempt.incorrect;
}

ostream& operator<<(ostream& ostr, const Response& attempt)
{
    ostr << "Correct: " << attempt.correct << "\nIncorrect: " << attempt.incorrect;
    return ostr;
}

#endif //PROJECT_1_RESPONSE_H
