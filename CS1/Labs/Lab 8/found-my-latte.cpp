#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

class latteGame {
    
    public:
    
    void mazeGenerator(); // Generates the maze and places coffee, latte, player
    void randGenerator(int x[2]); // Generates random coordinates for the given array
    void Play(); // Plays the game
    void PrintMatrix(); // Prints the maze
    
    
    private:
    
    char coffeeChar = 'C'; //to print out at the end to check "maze"
    char latteChar = 'L';  //^^^
    char playerChar = 'P'; //^^^
    char emptySpace = 'X'; //^^^
    int turns = 0; // Turns taken to find drink
    int timesWon = 0; // Times latte was found
    int coffee[2]; // Coordinates of coffee
    int latte[2]; // Coordinates of latte
    int player[2]; // Coordinates of player
    char matrixMaze[10][10]; // Maze
    
};

void latteGame::Play(){
    char response = 'y';
    
    while(tolower(response) == 'y'){
        mazeGenerator(); // Generate the maze
        bool won = 0;
        turns = 0;
        
        while(!won){
            char dir = 'a';
            while(dir != 'n' && dir != 's' && dir != 'w' && dir != 'e'){ // Ask user for direction
                cout << "Enter a direction to move (n/s/e/w): ";
                cin >> dir;
                dir = tolower(dir);
                if(dir != 'n' && dir != 's' && dir != 'w' && dir != 'e'){
                    cout << "Enter a valid direction.\n";
                }
            }
            double prevDistL = sqrt(pow(player[0] - latte[0], 2) + pow(player[1] - latte[1], 2)); // Calculate current distance to latte
            switch(dir){ // Move the player in the specified direction
                case 'n':
                    player[1]--;
                    break;
                case 's':
                    player[1]++;
                    break;
                case 'e':
                    player[0]++;
                    break;
                case 'w':
                    player[0]--;
                    break;
                default:
                    break;
            }
            double newDistL = sqrt(pow(player[0] - latte[0], 2) + pow(player[1] - latte[1], 2)); // Calculate new distance to latte
            
            if(prevDistL < newDistL) // Tell user if they got closer to or farther away from latte
                cout << "You got farther from the latte." << endl;
            else
                cout << "You got closer to the latte." << endl;
        
            turns++;
        
            if (matrixMaze[player[0]][player[1]] == 'L'){ // Determine if player found latte or coffee
                cout << "You found the latte!" << endl;
                won = 1;
                timesWon++;
            }
            else if(matrixMaze[player[0]][player[1]] == 'C'){
                won = 1;
                cout << "You found the coffee." << endl;
            }
        }
        
        cout << "Maze: " << endl;
        PrintMatrix();
        cout << "Turns taken: " << turns << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> response;
    }
    
    cout << "Times won: " << timesWon << endl;
    
}

void latteGame::PrintMatrix(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << matrixMaze[j][i];
        }
        cout << endl;
    }
}

void latteGame::randGenerator(int x[2]){
    
    int randomX = rand() % 10;
    int randomY = rand() % 10;
    x[0] = randomX;
    x[1] = randomY;

}

void latteGame::mazeGenerator(){
    
    for(int i = 0; i < 10; i++){ // Fill maze with 'empty' spaces
        
        for(int j = 0; j < 10; j++){
            
            matrixMaze[i][j] = 'X';
            
        }
        
    }
    
    randGenerator(coffee); // Generate random coordinates for coffee, latte, player
    randGenerator(latte);
    randGenerator(player);
    
    while(matrixMaze[coffee[0]][coffee[1]] != 'X') // Generate coordinates again if two things are placed in same location
        randGenerator(coffee);
        
    matrixMaze[coffee[0]][coffee[1]] = coffeeChar;

    while(matrixMaze[latte[0]][latte[1]] != 'X')
        randGenerator(latte);
        
    matrixMaze[latte[0]][latte[1]] = latteChar;

    while(matrixMaze[player[0]][player[1]] != 'X')
        randGenerator(player);
    
    matrixMaze[player[0]][player[1]] = playerChar;
    
}

int main() { // Seed RNG and play the game
    srand(time(0));
    
    latteGame game;
    
    game.Play();
    
    
    return 0;
}