//Katerina Betts
//Lab 4 Task 1
//September 19, 2017
//Task 1 requies a rollDie function to be created.

#include <iostream>
#include <cstdlib>
using namespace std;

int rollDie() {
   int x = 0;
   x = rand() % 6 + 1;
   return x;
}

int main(){
    
    int diceRoll = 0;
    int userVal = 0;
    int losses = 0;
    int wins = 0;

    srand(time(NULL));
    
    while (wins != 1 && losses != 3){
        
        diceRoll = rollDie();
        
        cout << "Enter a guess between the numbers 1 and 6: ";
        cin >> userVal;
        
        if (diceRoll != userVal){
            losses += 1;
        }
        else {
            wins += 1;
        }
        
        if(wins == 1) {
            cout << "You've won the game!!" << endl;
        }
        if (losses == 3) {
            cout << "You've lost the game!!" << endl;
            
        }
        
    }
    
    return 0;

}