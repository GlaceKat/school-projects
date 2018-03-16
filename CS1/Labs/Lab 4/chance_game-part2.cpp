//Katerina Betts
//Lab 4 Task 1
//September 19, 2017
//Task 1 requies a rollDie function to be created.

#include <iostream>
#include <cstdlib>
using namespace std;

int rollDie() { //Same function to simulate the rolling of the die.
   int x = 0;
   x = rand() % 6 + 1;
   return x;
}

int main(){
    
    int diceRoll = 0;
    int userVal = 0;
    int matches = 0;
    int nonMatches = 0;
    int losses = 0;
    int wins = 0;
    char userChar = 'y';
    
    srand(time(NULL));
    
    while(userChar == 'y'){
    
        matches = 0;
        nonMatches = 0;
    
        while (matches != 1 && nonMatches != 3){ //Necessary loop to keep track of wins and losses.
        
            diceRoll = rollDie();
        
            cout << "Enter a guess between the numbers 1 and 6: ";
            cin >> userVal;
        
            if (diceRoll != userVal){ //If statement in nested loop keeps track of how many times the die matches the guessed number.
                nonMatches += 1;
            }
            else {
                matches += 1;
            }
        
            if(matches == 1) {
                cout << "You've won the game!!" << endl;
            }
            if (nonMatches == 3) {
                cout << "You've lost the game!!" << endl;
            }

        }
    
    if(matches == 1){ //Number of wins and losses are incremented with each win/loss.
        wins = wins++;
    }
    if(nonMatches == 3){
        losses = losses++;
    }

    cout << "Would you like to continue?  (y/n) " << endl; //A character is used to either end the code or keep it looping forever.
    cin >> userChar;
    
    }
    return 0;
            
}