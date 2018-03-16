#include <iostream>
#include <algorithm>

using namespace std;

class Connect4{
    
    public:
    
    Connect4(); //constructor
    void fillBoard(); //fills the board with x's to signify null space
    void printBoard(); //prints out an empty board will all x's
    bool isWin(); //checks if there is a win on the board while playing
    void displayStats(); //displays the number of wins and losses of both players
    void placePiece(int column, char piece); //puts the piece on the board based on column chosen
    void playersTurn(char piece); //when a human player goes
    void computersTurn(); //when the AI is in the game and gets to play
    void start(); //Asks to play again and starts game
    void play(); //play the game Connect 4
    //~Connect4(); //destructor
    
    
    private:
    
    char firstPlayer = 'B'; //Black piece
    char secondPlayer = 'R'; //Red piece
    char nullSpace = 'X'; //Blank space
    static const int width = 7; //of board
    static const int height = 6; //of board
    char board[height][width]; //array with boards
    bool AI;
    int player1Wins=0;
    int player2Wins=0;
    int lastPlaced1 = 0;
    int lastPlaced2 = 0;
};

Connect4::Connect4(){
    int numPlayers = 0; // Ask user for number of players
    while(numPlayers != 2 && numPlayers != 1){
        cout << "Enter number of players (1-2): ";
        cin >> numPlayers;
        
        if(numPlayers != 2 && numPlayers != 1){
            cout << "Please enter a valid input." << endl;
        }
    }
    
    // Enable or disable AI
    if(numPlayers == 1){
        AI = 1;
    }
    else{
        AI = 0;
    }
}

void Connect4::fillBoard(){
    // Fill the board with null spaces
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            board[i][j] = nullSpace;
        }
    }
}

void Connect4::printBoard(){
    // Print out the board
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

bool Connect4::isWin(){
    bool win;
    // Check each space on the board and see if there are four in a row of the same kind
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++) {

			// Horizontal
			if (j < width - 3){
				win = true;
				for (int k = 0; k < 4; k++){
					if (board[i][j + k] == nullSpace || board[i][j + k] != board[i][j])
						win = false;
				}
				if (win)
					return true;
			}

			// Vertical
			if (i < height - 3){
				win = true;
				for (int k = 0; k < 4; k++){
					if (board[i + k][j] == nullSpace || board[i + k][j] != board[i][j])
						win = false;
				}
				if (win)
					return true;
			}

			//Diagonal down-right
			if (i < height - 3 && j < width - 3){
				win = true;
				for (int k = 0; k < 4; k++){
					if (board[i + k][j + k] == nullSpace || board[i+k][j+k] != board[i][j])
						win = false;
				}
				if (win)
					return true;
			}

			//Diagonal down-left
			if (i < height - 3 && j >= 3){
				win = true;
				for (int k = 0; k < 4; k++){
					if (board[i + k][j - k] == nullSpace || board[i+k][j-k] != board[i][j])
						win = false;
				}
				if (win)
					return true;
			}
		}
	}

	return false;
}

void Connect4::displayStats(){
    // Display the stats after the game is over
    cout << endl;
    cout << "Player 1 had: " << endl;
    cout << player1Wins << " Win(s)" << endl;
    cout << player2Wins << " Loss(es)" << endl;
    cout << "AND" << endl;
    cout << "Player 2 had: " << endl;
    cout << player2Wins << " Win(s)" << endl;
    cout << player1Wins << " Loss(es)" << endl;
    cout << "Over the course of " << player1Wins + player2Wins << " game(s).";
    
}

void Connect4::placePiece(int column, char piece){
    // Place a piece at a specified column
    column--;
    for(int i = 0; i < height; i++){ // Loops down the column until it hits a non-empty space
        if(board[i][column] != nullSpace){
            board[i-1][column] = piece;
            return;
        }
    }
    
    board[height-1][column] = piece;
}

void Connect4::play(){
    
    printBoard();

    // Give each player a turn while there is not a win on the board
    while(!isWin()){
        cout << "Player 1's Turn: " << endl;
        playersTurn(firstPlayer);
        
        printBoard();
        
        if(isWin()){
            cout << "Player 1 Wins!" << endl;
            player1Wins++;
            return;
        }
        
        cout << "Player 2's Turn: " << endl;
        
        // If there is AI, let it play, otherwise give player 2 a turn
        if(AI){
            computersTurn();
        }
        else{
            playersTurn(secondPlayer);
        }
        
        printBoard();
        
        if(isWin()){
            cout << "Player 2 Wins!" << endl;
            player2Wins++;
        }
    }
}

void Connect4::start(){
    // Plays the game while the user wants to
    char p = 'y';
    while(tolower(p) == 'y'){
        fillBoard();
        play();
        
        cout << "Do you want to play again? (y/n): ";
        cin >> p;
    }
    
    // Display stats at end of game
    displayStats();
}

void Connect4::playersTurn(char piece){
    
    int column = 0;
    
    // Ask user to place piece in column
    while(column < 1 || column > 7){
        cout << "Please select the column in which you will place your piece (1-7): ";
        cin >> column;
        
        if(column < 1 || column > 7){
            cout << "Please enter a valid input." << endl;
        }
    }
    placePiece(column, piece);
    
    // Keep track of previous moves for AI
    lastPlaced2 = lastPlaced1;
    lastPlaced1 = column;
}

void Connect4::computersTurn(){
    int column;

    // If last two moves are in a row, AI places in that row to block
    // If last two moves are in column, AI places in that column to block
    // Otherwise, choose random column
    if(lastPlaced2 == 0){
        column = rand() % 7 + 1;
    }
    else if(lastPlaced1 == lastPlaced2){
        column = lastPlaced1;
    }
    else if(lastPlaced1 - lastPlaced2 == 1){
        column = min(7, lastPlaced1 + 1);
    }
    else if(lastPlaced1 - lastPlaced2 == -1){
        column = max(0, lastPlaced1 - 1);
    }
    else{
        column = rand() % 7 + 1;
    }

    
    placePiece(column, secondPlayer);
    
}

int main(){
    // Create a game object and start playing
    Connect4 game;
    game.start();
    
    return 0;
}