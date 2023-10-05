
#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Code class: constructed with parameters n and m, and a secret code is 
// initialized with n digits each in the range [0, m-1].
class Code 
{

    // Public member function
public:
    Code();
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

// Code constructor to initialize the code object with n random digits in the
// range [0, m-1]
Code::Code(int n, int m) 
{
    _length = n;
    _range = m;
}

// initializeCode function: used to reset the secret code randomly
void Code::initializeCode() 
{
    srand(time(0));

    vector<int> vec;

    for (int i = 0; i < _length; i++)
    {
        int random = rand() % _range;
        vec.push_back(random);
    }

    setSequence(vec);
    
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

// checkCorrect function: used to check the number of correct digits in the 
// correct location
int Code::checkCorrect(Code& guess) 
{
    int count = 0;

    for (int i = 0; i < sequence.size(); i++)
        if (sequence[i] == guess.sequence[i])
            count++;

    return count;
}

// checkIncorrect function: used to check the number of correct digits in the 
// incorrect location
int Code::checkIncorrect(Code& guess) 
{
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
void Code::display() 
{

    for(const int & i : sequence)
        std::cout << i << " ";
    cout << endl;

}

#endif
