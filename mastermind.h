// PART B
// Last edited: Neha - 10/3 1:30PM


#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "code.h"
#include "response.h"
#include <iostream>


// Mastermind class: manages and plays Mastermind game
class Mastermind {
    // Public member functions
    public:
        // Default constructor: initializes game with default values n=5 and m=10
        Mastermind() : code(5, 10) {}

        // Parameter constructor: game settings
        Mastermind(int n, int m) : code(n, m) {}
        void printSecretCode();
        Code humanGuess(int n, int m);
        const Response getResponse(const Code& guess);
        bool isSolved(const Response& response);
        void playGame();

    // Private member function
    private:
        // gameCode function: secret code for the game
        Code code;
};

// printSecretCode function: prints the secret code
void Mastermind::printSecretCode()
{
    code.display();
}

// humanGuess function: get user input guess
Code Mastermind::humanGuess(int n, int m)
{
    vector<int> guessVec(n);
    cout << "Enter your guess (must be an integer from 0 and " << m-1 << "): ";
    for (int i : guessVec) 
    {
        int guessDigit;
        cin >> guessDigit;   // guess = user input
        while (guessDigit >= m || guessDigit < 0)
        {
            cout << "Guess is out of range, please reenter." << endl;
            cin >> guessDigit;
        }
    }
    Code guessCode(n, m);
    guessCode.setSequence(guessVec);
    return guessCode;
}


// getResponse function: generate response based on user input
const Response Mastermind::getResponse(const Code &guess)
{
    return Response(code.checkCorrect(guess), code.checkIncorrect(guess));
}


// isSolved function: checks if user's guess = solved game
bool Mastermind::isSolved(const Response &guess)
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
    // Check if the user entered length is long enough
    while (length <= 3){
        cout << "Enter a length for the code (must be > 3):" << endl;
        cin >> length;
        if (length <= 3)
            {
                cout << "Noy a valid length, try again";
                cin >> length;
            }
    }
    // Check if the user entered range is long enough
    while(range <= 4){
        cout << "Enter a range for the sequence (must be > 4): " << endl;
        cin >> range;
        if (range <= 4)
            {
                cout << "Not a valid range, try again";
                cin >> range;
            }
    }

    Mastermind secret(length, range);
    secret.code.initializeCode();  // Generate new secret code
    printSecretCode(); // Print secret code

    bool solved = false; 

    while (true)    // Keep looping until game is solved
    {
        Mastermind guess(length, range);
        guess.code = humanGuess(length,range);  // Get a guess from the user
        Response response = guess.getResponse(secret.code); // Generate response for the guess
        cout << response << '\n';   // Response output
        if (solved == (isSolved(response))) {   // Check if response = solved game
            cout << "You solved the code! YIPPEE!!\n";
            break;  // Exit loop
        }
    }
}



#endif //PROJECT_1_MASTERMIND_H
