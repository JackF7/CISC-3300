/* CISC 1610 - Computer Science I Lab
 * Final Project
 *
 * This program generates a game of tic-tac-toe.
 *
 * Jack Forester 
 * Last Edited: December 9, 2023
 */

#include <iostream>
#include <string>
#include <ctime>
#include <fstream> 

using namespace std;

// Board Dimensions
const int numRows = 3;
const int numColumns = 3;

void drawBoard(char board[][numColumns]);
// Pre-Conndition: Updated Tic-Tac-Toe board not shown. Player input not shown.
// Post-Condition: Player input shown on board.
    
bool playerSelection (bool& player1First, char& playerSymbol);
// Pre-Condition: Player who goes first not generated.
// Post-Condition: Random generation of which player goes first returned as a bool.

bool playGame (bool firstTurn, char board[][numColumns], char playerSymbol, int& player1Wins, int& player2Wins);
// Pre-Condition: Game not started.
// Post-Condition: Game begins.

void checkMove (const char board [][numColumns], int& userRow, int& userColumn);
// Pre-Condition: Validity of user's move is unknown.
// Post-Condition: Validity of user's move is known.

bool checkWin (const char board [][numColumns], char playerSymbol, int& player1Wins, int& player2Wins);
// Pre-Condition: Win condition unknown
// Post-Condition: Win condition known

bool repeatGame (char board[][numColumns], char playerSymbol, int& numGamesPlayed, int player1Wins, int player2Wins, bool win);
// Pre-Condition: Player has won game.
// Post-Condition: Prints result, total score, and congratulations. Resets board. Repeats or ends the game.

void resetBoard (char board[][numColumns]);
// Pre-Condition: Board has values stored of previous game
// Post-Condition: Board values are reset to empty spaces

void gamesWon (int player1Wins, int player2Wins);
// Pre-Condition: Number of games won not displayed.
// Post-Condition: Number of games won displayed. This tedious function ensures that "game" is singular or plural based on the number of games a player has won

void newLine (istream& inStream);
// Pre-Condition: Extra spaces or characters remain
// Post-Condition: Clears any extra spaces or characters input by the user
    
int main() {  

// Greeting

    cout << "Greetings, and welcome to Tic-Tac-Toe! Before you begin, let's go over the basic rules of the game. Player 1 (X's) and Player 2 (O's) will take turns placing their respective symbols on the Tic-Tac-Toe board. The first player to place three X's or O's in a row, column, or diagonal wins! If nobody manages to succeed after the board is filled, you tie. Good luck!" << endl << endl;
    
// Board Array Initialization

    char board[numRows][numColumns] = { 
        {' ', ' ',' '},
        {' ', ' ',' '},
        {' ', ' ',' '}
    };
    drawBoard(board);

// Random Player Selection 
    
    char symbol;
    bool firstTurn, gameFinished = false;
    int player1TotalWins = 0, player2TotalWins = 0, numGamesPlayed = 0;
    
    while (!gameFinished) {
        playerSelection (firstTurn, symbol); 
        // Player Selection. firstTurn = true if Player 1 goes first. firstTurn = false is Player 2 goes first
        
    // The Game    
   
       bool win = playGame (firstTurn, board, symbol, player1TotalWins, player2TotalWins);
   
    // Play Again?
    
        bool again = repeatGame(board, symbol, numGamesPlayed, player1TotalWins, player2TotalWins, win);
                    
        if (!again) {
                    
            cout << endl << "Thanks for playing!" << endl;
            gameFinished = true;
        }
        else if (again) {
            
            gameFinished = false;
            cout << endl;
            drawBoard(board);
            cout << "Let's do it!";
        }
    }
    
    return 0;
}

void drawBoard(char board[][numColumns]) {
    
   cout << ":)    1     2     3    (:" << endl; // Print column numbers
   cout << "   ___________________" << endl;
   
   for (int i = 0; i < numRows; i++) {
        cout << "   |     |     |     |" << endl << i + 1 << "  |"; // Print row numbers
        
        for (int j = 0; j < numColumns; j++) {
            cout << "  " << board[i][j] << "  |"; // Print board elements
        }
        
        cout << endl;
        cout << "   |_____|_____|_____|" << endl; // Print horizontal lines
    }
    
    cout << endl; // Creates some space between bottom of the board and the next text
}
  
bool playerSelection (bool& player1First, char& playerSymbol) {
    
    srand(time(0));
    
    if (rand() % 2 == 0) {
       player1First = true;
    }
    else {
       player1First = false;
    } 
    
    if (player1First) {
        cout << endl << "Player 1 (X's), you will go first. Please enter your row and column with a space in between: ";
        playerSymbol = 'X';
        player1First = false; // Changes turn to Player 2
    }
    else if (!player1First) {
        cout << endl << "Player 2 (O's), you will go first. Please enter your row and column with a space in between: ";
        playerSymbol = 'O';
        player1First = true; // Changes turn to Player 1
    }

    return player1First;
}

bool playGame (bool firstTurn, char board[][numColumns], char playerSymbol, int& player1Wins, int& player2Wins) {
   
    bool playAgain = true;  
    int row, column;
    ifstream ins; 
    
    // First turn after printing which player goes first

    cin >> row >> column;
    newLine(cin); // Clears any extra spaces or characters
    cout << endl; // Creates some space between the text and board
    checkMove (board, row, column);
    board[row - 1][column - 1] = playerSymbol;
    drawBoard (board);
    
    for (int numTurns = 1; numTurns < 9; numTurns++) {
        
        if (firstTurn) {
            cout << "Player 1 (X's), enter your row and column with a space in between: ";
            playerSymbol = 'X';
            firstTurn = false;
            }
            else if (!firstTurn) {
            cout << "Player 2 (O's), enter your row and column with a space in between: ";
            playerSymbol = 'O';
            firstTurn = true;
            }
        
        cin >> row >> column;
        newLine(cin); // Clears any extra spaces or characters
        cout << endl; // Creates some space between the text and board
        checkMove (board, row, column);
        board[row - 1][column - 1] = playerSymbol;
        drawBoard (board);
    
        if (numTurns >= 4) {
            
            bool win = checkWin (board, playerSymbol, player1Wins, player2Wins); 
            // Checks to see if a player has won and would like to play again
                
            if (win) {
                    
                return true;
            } 
        }   
    }
        
    return false;
}

void checkMove (const char board [][numColumns], int& userRow, int& userColumn) {

    bool validMove = (userRow >= 1 && userRow <= 3 && userColumn >= 1 && userColumn <= 3);
    bool alreadyMade = (board[userRow - 1][userColumn - 1] == 'X' || board[userRow - 1][userColumn - 1] == 'O');
    
    while (!validMove || alreadyMade) {
       
        if (!validMove) {
            
            cout << "Invalid move. Please choose a valid spot." << endl;
        }
        else if (alreadyMade) {
            
            cout << "Move already made. Please choose another spot." << endl;
        }
        
        cin >> userRow >> userColumn;
        validMove = (userRow >= 1 && userRow <= 3 && userColumn >= 1 && userColumn <= 3);
        alreadyMade = (board[userRow - 1][userColumn - 1] == 'X' || board[userRow - 1][userColumn - 1] == 'O');
    }
}

bool checkWin (const char board [][numColumns], char playerSymbol, int& player1Wins, int& player2Wins) {
    
    bool gameWin = false;
    
    // Check rows and columns for a win
    
    for (int i = 0; i < numRows; i++) {
        
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol) {
            
            gameWin = true; // Row win
            break;
        }
        else if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol) {
            
            gameWin = true; // Column win
            break;
        }
    }    
    
    if ((board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) || (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)) {
            
        gameWin = true; // Diagonal win
    }
    
    // Score Counting
    
    if (gameWin && playerSymbol == 'X') {
        player1Wins++;
    }
    else if (gameWin && playerSymbol == 'O') {
        player2Wins++;
    }
    
    return gameWin;
}

bool repeatGame (char board[][numColumns], char playerSymbol, int& gamesPlayed, int player1Wins, int player2Wins, bool win) {
    
    bool oneMoreRound;
    char playAgain;
    
    if (win) {

        if (playerSymbol == 'X') {
        
            cout << "Congratulations, Player 1 (X's)! You win!" << endl << endl;
        }
        else if (playerSymbol == 'O') {
        
            cout << "Congratulations, Player 2 (O's)! You win!" << endl << endl;
        }    
    }
    
    if (!win) {
        cout << "It's a tie!" << endl;
    }
    
    gamesPlayed++;
    resetBoard (board);
    
    // End-of-Game Display
    
    cout << "Scoreboard:" << endl << endl;
    gamesWon (player1Wins, player2Wins);
    cout << "Total Games Played: " << gamesPlayed << endl << endl;
    cout << "Would you like to play again? (Y/N): ";
    
    cin >> playAgain;
    while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
        
        cout << "Please select 'Y' or 'N' to continue.";
    }
    
    if (playAgain == 'Y' || playAgain == 'y') {
           
        oneMoreRound = true;
    }
    else if (playAgain == 'N' || playAgain == 'n') {
    
        oneMoreRound = false;
    }
    
    return oneMoreRound;
}

void resetBoard (char board[][numColumns]) {
    
    for (int i = 0; i < numRows; i++) {
        
        for (int j = 0; j < numColumns; j++) {
            
            board[i][j] = ' ';
        }
    }
}

void gamesWon (int player1Wins, int player2Wins) {
    
    if (player1Wins != 1 && player2Wins != 1) {
    
        cout << "Player 1: " << player1Wins << " Games Won" << endl
             << "Player 2: " << player2Wins << " Games Won" << endl;
    }   
    else if (player1Wins == 1 && player2Wins != 1) {
        
        cout << "Player 1: " << player1Wins << " Game Won" << endl
             << "Player 2: " << player2Wins << " Games Won" << endl;
    }
    else if (player1Wins != 1 && player2Wins == 1) {
        
        cout << "Player 1: " << player1Wins << " Games Won" << endl
             << "Player 2: " << player2Wins << " Game Won" << endl;
    }
    else if (player1Wins == 1 && player2Wins ==1) {
        
        cout << "Player 1: " << player1Wins << " Game Won" << endl
             << "Player 2: " << player2Wins << " Game Won" << endl;
    }
}

void newLine (istream& inStream) {
     char symbol;
     do {
         inStream.get(symbol);
     }  while (symbol != '\n');
} 