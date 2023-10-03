// PART B
// Last edited: Neha - 10/3 1:30PM


#ifndef PROJECT_1_MASTERMIND_H
#define PROJECT_1_MASTERMIND_H
#include "code.h"
#include "Response.h"


// Mastermind class: manages and plays Mastermind game
class Mastermind {
    // Public member functions
    public:
        // Default constructor: initializes game with default values n=5 and m=10
        Mastermind() : gameCode(5, 10) {}

        // Parameter constructor: game settings
        Mastermind(int n, int m) : gameCode(n, m) {}

        void printSecretCode)();
        Code humanGuess();
        Response getResponse(const Code& guess);
        bool isSolved(const Response& response);
        void playGame();

    // Private member function
    private:
        // gameCode function: secret code for the game
        Code gameCode;
};


// printSecretCode function: prints the secret code
void Mastermind::printSecretCode()
{
    gameCode.display();
}


// humanGuess function: get user input guess
Code Mastermind::humanGuess()
{
    int n = gameCode;
    vector<int> guessVec(n);
    cout << "Enter your guess: ";
    for (int &i : guessVec) cin >> i;   // guess = user input
    Code guessCode(n, gameCode);
    guessCode.setSequence(guessVec);
    return guessCode;
}


// getResponse function: generate response based on user input
Response Mastermind::getResponse(const Code &guess)
{
    return Response(gameCode.checkCorrect(guess), gameCode.checkIncorrect(guess));
}


// isSolved function: checks if user's guess = solved game
bool Mastermind::isSolved(const Response &response)
{
    return response == gameCode;
}


// playGame function: the main game loop which initializes game,
// accepts guesses, and provides feedback until the game is solved
void Mastermind::playGame()
{
    gameCode.initializeCode();  // Generate new secret code
    printSecretCode();
    while (true)    // Keep looping until game is solved
    {
        Code guess = humanGuess();  // Get a guess from the user
        Response response = getResponse(guess); // Generate response for the guess
        cout << response << '\n';   // Response output
        if (isSolved(response)) {   // Check if response = solved game
            cout << "You solved the code! YIPPEE!!\n";
            break;  // Exit loop
        }
    }
}



#endif //PROJECT_1_MASTERMIND_H
