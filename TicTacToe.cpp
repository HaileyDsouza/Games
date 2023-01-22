#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int SIZE = 3;
void generateComputerMove(string board[][SIZE]);
bool foundBestPosition(int leftPos, int rightPos, int colToPlace, int i, string board[][SIZE]);
bool checkEachCol(int i, string board[][SIZE]);
void displayBoard(string b[][SIZE]);
bool userFirst();
bool currentPlayerWon(string b[][SIZE], string symbol);

int main()
{
    //construct board
    string board[SIZE][SIZE];
    int position_id = 1;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = to_string(position_id);
            /*  stringstream ss;
       ss << position_id;
       board[i][j] = ss.str();
       */
            position_id++;
        }
    }
    //Initial game output
    cout << "Welcome to Tic-Tac-Toe" << endl;
    bool userTurn = userFirst();
    if (userTurn == true)
    {
        cout << "Player goes first!" << endl;
    }
    else
    {
        cout << "Computer goes first!" << endl;
    }
    //Loop for turn taking in game
    int positionsRemaining = SIZE * SIZE;
    bool userWon = false;
    bool computerWon = false;
    while ((positionsRemaining > 0) && (!userWon) && (!computerWon))
    {
        displayBoard(board);
        //User's turn
        if (userTurn)
        {
            bool validMove = false;
            while (!validMove)
            {
                int position_id;
                cout << "Enter a position: ";
                cin >> position_id;
                if ((position_id <= (SIZE * SIZE)) && (position_id > 0))
                {
                    int row = (position_id - 1) / SIZE;
                    int col = (position_id - 1) % SIZE;
                    //cout << "row = " << row << " col = " << col << endl;
                    if ((board[row][col] != "X") && (board[row][col] != "O"))
                    {
                        board[row][col] = "X";
                        validMove = true;
                    }
                    else
                    {
                        cout << "Position already used. Try again." << endl;
                    }
                }
                else
                {
                    cout << "Position invalid. Try again." << endl;
                }
            }
            positionsRemaining--;
            userWon = currentPlayerWon(board, "X");
            userTurn = false;
        }
        //Computer's turn
        else
        {
            //The row and col are both passed as
            //call-by-reference
            int row, col;
            generateComputerMove(board);
            //board[row][col] = "O";
            positionsRemaining--;
            computerWon = currentPlayerWon(board, "O");
            userTurn = true;
        }
    }
    //Display game result
    displayBoard(board);
    if (userWon)
    {
        cout << "Congratulations! You have won!" << endl;
    }
    else if (computerWon)
    {
        cout << "The computer has won. Try again." << endl;
    }
    else
    {
        cout << "Out of moves. Try again." << endl;
    }
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// generating the computers move
void generateComputerMove(string board[][SIZE])
{

    bool placed = false;           // if nothing is placed
    for (int i = 0; i < SIZE; i++) //checks each row
    {
        placed = checkEachCol(i, board); // goes into the checkEachCol function
        if (placed)
        {
            break; //it there is a good spot you place the 0
        }
    }
    // if can't find a good spot then you pick an open spot but loop through the rows/cols
    if (!placed)
    {
        for (int i = 0; i < SIZE; i++) // this makes it faster
        {
            for (int j = 0; j < SIZE; j++)
            {
                if ((board[i][j] != "X") && (board[i][j] != "O"))
                {
                    board[i][j] = "O";
                    return;
                }
            }
        }
    }

    return;
}
// when you find the best position, then place the symbol O
bool foundBestPosition(int leftPos, int rightPos, int colToPlace, int i, string board[][SIZE])
{
    if (board[i][leftPos] == board[i][rightPos]) // if the leftt equals the right then place O
    {
        if ((board[i][colToPlace] != "X") && (board[i][colToPlace] != "O"))
        {
            board[i][colToPlace] = "O";
            return true;
        }
    }
    return false;
}
// in order to check each col so that the computer can block
bool checkEachCol(int i, string board[][SIZE])
{

    bool found = false;                           // while the good spot hasn't been found yet
    found = foundBestPosition(0, 1, 2, i, board); // spot 0 and 1, then place in spot 2
    if (found)
    {
        return found;
    }
    found = foundBestPosition(1, 2, 0, i, board); // spot 1 and 2, then place in spot 0
    if (found)
    {
        return found;
    }
    return foundBestPosition(0, 2, 1, i, board); // spot 0 and 2, then place in spot 1
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void displayBoard(string b[][SIZE])
{
    cout << "Tic-tac-toe board:" << endl
         << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
bool userFirst()
{
    //set seed for random number generation
    srand(time(NULL));
    //generate a random number
    //0 for computer
    //1 for user
    int num = rand() % 2;
    if (num == 0)
    {
        return false;
    }
    return true;
}
//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string b[][SIZE], string symbol)
{
    //Horizontal case
    //Loop through each row
    for (int i = 0; i < SIZE; i++)
    {
        bool rowWinDetected = true;
        //Check all positions in row and see if they are the same symbol
        for (int j = 0; j < SIZE; j++)
        {
            if (b[i][j] != symbol)
            {
                rowWinDetected = false;
            }
        }
        if (rowWinDetected)
        {
            return true;
        }
    }
    //Vertical case
    //Loop through each column
    for (int i = 0; i < SIZE; i++)
    {
        bool colWinDetected = true;
        //Check all positions in column and see if they are the same symbol
        for (int j = 0; j < SIZE; j++)
        {
            if (b[j][i] != symbol)
            {
                colWinDetected = false;
            }
        }
        if (colWinDetected)
        {
            return true;
        }
    }
    //Diagonal case #1
    bool diagonal1WinDetected = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (b[i][i] != symbol)
        {
            diagonal1WinDetected = false;
        }
    }
    if (diagonal1WinDetected)
    {
        return true;
    }
    //Diagonal case #2
    bool diagonal2WinDetected = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (b[(SIZE - 1) - i][i] != symbol)
        {
            diagonal2WinDetected = false;
        }
    }
    if (diagonal2WinDetected)
    {
        return true;
    }
    //otherwise win not diagonal2WinDetected
    return false;
}
