//Katerina Betts
//Lab 4 Task 1
//September 19, 2017
//Task 1 requies a rollDie function to be created.
/*As I complete more tasks, the more refined the code is becoming.*/

#include <iostream>
#include <cstdlib>
using namespace std;

int rollDie() { //Same function to simulate the rolling of the die.
   int x = 0;
   x = rand() % 6 + 1;
   return x;
}

bool playOneGame(){
    
    int diceRoll = 0;
    int userVal = 0;
    int matches = 0;
    int nonMatches = 0; 
    int i = 1;
    
    while (matches != 1 && nonMatches != 3){ //Necessary loop to keep track of wins and losses.
        
            diceRoll = rollDie();
        
            cout << "Enter a guess between the numbers 1 and 6: ";
            cin >> userVal;
            while(userVal < 0 || userVal > 6){
                cout << "Error! Enter a number between 1 and 6: ";
                cin >> userVal;
            }
            
            cout << "Roll #" << i << " is " << diceRoll << "!" << endl;
            i = i + 1;
            
            if (diceRoll != userVal){ //If statement in nested loop keeps track of how many times the die matches the guessed number.
                nonMatches += 1;
            }
            else {
                matches += 1;
            }
        
            if(matches == 1) {
                cout << "You've won the game!!" << endl;
                return 1;
            }
            if (nonMatches == 3) {
                cout << "You've lost the game!!" << endl;
                return 0;
            }

        }
        
}

int main(){
    
    bool onePlay = 0;
    int losses = 0;
    int wins = 0;
    char userChar = 'y';
    double bankAccount = 100.00;
    double wager = 0;
    
    srand(time(NULL));
    
    while(userChar == 'y'){
        
        cout << "Please enter a wager (0 to exit): ";
        cin >> wager;
        
        while(wager > bankAccount || wager < 0){
            cout << "Error!!  Please enter a valid wager: ";
            cin >> wager;
        }
        
        cout << "Your wager is $" << wager << " for a single play!" << endl;
        
        onePlay = playOneGame();   
    
        if(onePlay == 1){ //Number of wins and losses are incremented with each win/loss.
            wins = wins++;
        }
        if(onePlay == 0){
            losses = losses++;
        }

        cout << "Would you like to play again?  (y/n) " << endl; //A character is used to either end the code or keep it looping forever.
        cin >> userChar;
    
    }
    return 0;
            
}