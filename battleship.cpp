#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "-----------------------------" << endl;
    cout << "Welcome To Battleship Lite!" << endl;
    cout << "-----------------------------" << endl;

    int roundNum = 1; // initalize the round
    int battleShip;

    const int RANGE = 5;
    int guess;
    bool goToNextRound = true;
    int boardSize = 0;
    char response;

    while (goToNextRound == true) // in order to go to next round
    {
        cout << "Round " << roundNum << endl;
        roundNum += 1; // adds a round each time

        boardSize += 10; // random num goes up by 10
        battleShip = rand() % boardSize;
        char board[boardSize] = {};
        for (int i = 0; i < boardSize; i++)
        {
            board[i] = '-'; // prints the same amount of dashes
        }

        //cout << "battleship num: " << battleShip << endl;

        //guesses
        for (int i = 0; i < RANGE; i++)
        {
            cout << "Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9" << endl;
            for (int i = 0; i < boardSize; i++)
            {
                if (i % 10 == 0)
                {
                    cout << endl;
                }
                cout << board[i] << " "; // space in between
            }
            cout << "" << endl;
            cout << "Guess a location of battleship " << endl;
            cin >> guess;

            board[guess] = 'x'; // x where the hit is
            if (guess == battleShip)
            {
                cout << "Hit" << endl;
                goToNextRound = true;
                break;
            }
            else
            {
                cout << "Miss" << endl
                     << "" << endl
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                goToNextRound = false;
            }
        }
        if (goToNextRound == false)
        {
            break;
        }
        cout << "play again ? [y]es or [n]o " << endl; // play again
        cin >> response;
        if (response == 'n')
        {
            break;
        }
    }

    return 0;
}