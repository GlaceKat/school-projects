#include <iostream>
#include <time.h>

using namespace std;

// Class for Guessing Game
class GuessingGame{
    public:
    GuessingGame(); // Constructor
    void Play(); // Play the game

    private:
    int randNum; // Randomly generated number
    int totalGuesses; // Total number of guesses
    int totalWins; // Total number of wins
    bool MakeGuess(int n); // Guess the number
    void SetNum(); // Set the randomly generated number
};

// Constructor initializes the randomly generated number
GuessingGame::GuessingGame(){
    srand(time(NULL));
    totalGuesses = 0;
    totalWins = 0;
    SetNum();
}

// Play the game
void GuessingGame::Play(){
    char response = 'y';
    
    // Play while the user
    while(tolower(response) == 'y'){
        SetNum();
        
        bool correct = 0;
        int numGuesses = 0;
        while(numGuesses < 7 && !correct){ // Loop until the user guesses the answer or runs out of guesses
            int guess;
            cout << "Enter a guess: ";
            cin >> guess;
    
            correct = MakeGuess(guess); // Make a guess with the user entered value
            numGuesses++;
        }
        
        if(!correct){
            cout << "You lose..." << endl;
        }
    
        cout << "Do you want to play again? (y/n): "; // Ask the user to play again
        cin >> response;
    }
    
    cout << "Total number of guesses: " << totalGuesses << endl;
    cout << "Total number of wins: " << totalWins << endl;
}

// Tell the user if the guess is higher, lower, or correct. Return true if correct
bool GuessingGame::MakeGuess(int n){
    totalGuesses++;
    if(n > randNum){
        cout << "Guess lower!" << endl;
        return 0;
    }
    else if(n < randNum){
        cout << "Guess higher!" << endl;
        return 0;
    }
    else
    {
        cout << "You guessed correctly!" << endl;
        totalWins++;
        return 1;
    }
    
}

// Set the random number to the specified value
void GuessingGame::SetNum(){
    randNum = rand() % 100 + 1;
}

// Main function creates a game object and plays
int main()
{
    GuessingGame g;
    g.Play();
    
    return 0;
}