// Project 1 for EECE2560
//Part B
//
//Collaborators: Madeline Coco, Neha Joby
//This file contains the Mastermind class.



#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "code.h"
#include "response.h"
#include <iostream>


// Mastermind class: manages and plays Mastermind game
class Mastermind {
    // Public member functions
    public:
        // Default constructor: initializes game with values n=5 and m=10
        Mastermind() : code(5, 10) {}

        // Parameter constructor: game settings
        Mastermind(int n, int m) : code(n, m) {}
        void printSecretCode();
        Code humanGuess(int n, int m);
        Response getResponse(Code& guess);
        bool isSolved(Response& response);
        void playGame();

    // Private member function
    private:
        // gameCode function: code for the game
        Code code;
};

// printSecretCode function: prints the secret code
void Mastermind::printSecretCode()
{   
    cout << "\nSECRET CODE:" << endl;
    code.display();
    cout << endl;
}

// humanGuess function: get user input guess, with two input
// parameters (length and range for the code)
Code Mastermind::humanGuess(int n, int m)
{
    vector<int> guessVec(n);
    cout << "Enter your guess digit by digit (must be an integer from ";
    cout << "0 and " << m-1 << "): ";

    for(int i = 0 ; i < n ; i++)
    {
        int guessDigit;
        cin >> guessDigit;   // guess = user input

        while (guessDigit >= m || guessDigit < 0)
        {
            cout << "Guess is out of range, please reenter." << endl;
            cin >> guessDigit;
        }

        guessVec[i] = guessDigit;
    }

    Code guessCode(n, m);

    guessCode.setSequence(guessVec);
    return guessCode;
}


// getResponse function: generate response based on user input
// calls setResponses to compare guess code and secret code
Response Mastermind::getResponse(Code& secret)
{
    Response newResponse;
    newResponse.setResponses(code, secret);
    return newResponse;
}


// isSolved function: checks if user's guess = solved game
bool Mastermind::isSolved(Response& guess)
{
    Response response = getResponse(code);
    return response == guess;
}


// playGame function: the main game loop which initializes game,
// accepts guesses, and provides feedback until the game is solved
void Mastermind::playGame()
{
    // Ask player for length and range
    int length = 0;
    int range = 0;

    cout << "Enter a length for the code (must be > 3):" << endl;

    // Check if the user entered length is long enough
    while (length <= 3){
        cin >> length;
        if (length <= 3)
            {
                cout << "Not a valid length, try again";
            }
    }

    cout << "Enter a range for the sequence (must be > 4): " << endl;

    // Check if the user entered range is long enough
    while(range <= 4)
    {
        cin >> range;
        if (range <= 4)
            {
                cout << "Not a valid range, try again";
            }
    }

    Mastermind secret(length, range);
    secret.code.initializeCode();  // Generate new secret code
    secret.printSecretCode(); // Print secret code

    bool solved = false; 

    // Keep looping until game is solved or 10 guesses
    for(int i = 0; i < 10; i++)  
    {
        Mastermind guess(length, range);
        guess.code = humanGuess(length,range);  // Get a guess from the user
        Response response = guess.getResponse(secret.code); 
        cout << response << '\n';   

        if (true == (secret.isSolved(response))) {   
            solved = true;
            break;  // Exit loop when solved
        }
    }

    // Game output - win or lose
    if(solved)
    {
        cout << "You solved the code! YIPPEE!!\n";
    }
    else
    {
        cout << "You exceeded 10 guesses. Better luck next time.";
    }
}



#endif //PROJECT_1_MASTERMIND_H
