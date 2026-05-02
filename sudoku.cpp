#include <iostream>
using namespace std;

int board[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},

    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 6, 0},

    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

bool fixedCell[9][9];

void printBoard()
{
    cout << "\nSudoku Board:\n";
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
            cout << "-----------------------\n";

        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
                cout << "| ";

            // print . instead of 0
            if (board[i][j] == 0)
                cout << "0 ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void initializeFixed()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            fixedCell[i][j] = (board[i][j] != 0);
}

// check valid move
bool isSafe(int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
        if (board[row][i] == num)
            return false;

    for (int i = 0; i < 9; i++)
        if (board[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// find empty cell
bool findEmpty(int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (board[row][col] == 0)
                return true;

    return false;
}

// solve sudoku
bool solveSudoku()
{
    int row, col;

    if (!findEmpty(row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku())
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

// check complete
bool isComplete()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == 0)
                return false;

    return true;
}

void playGame()
{
    int row, col, num;

    while (true)
    {
        printBoard();

        if (isComplete())
        {
            cout << "🎉 Congratulations! You solved the Sudoku!\n";
            break;
        }

        cout << "\nEnter row (1-9), column (1-9), number (0-9): ";
        cin >> row >> col >> num;

        row--;
        col--;

        if (row < 0 || row > 8 || col < 0 || col > 8 || num < 0 || num > 9)
        {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (fixedCell[row][col])
        {
            cout << "Cannot change this cell!\n";
            continue;
        }

        // erase option
        if (num == 0)
        {
            board[row][col] = 0;
            continue;
        }

        if (isSafe(row, col, num))
        {
            board[row][col] = num;
        }
        else
        {
            cout << "Invalid move!\n";
        }
    }
}

int main()
{
    initializeFixed();

    int choice;
    cout << "1. Play Sudoku\n2. Auto Solve\nChoose option: ";
    cin >> choice;

    if (choice == 1)
    {
        playGame();
    }
    else if (choice == 2)
    {
        if (solveSudoku())
        {
            cout << "\nSolved Sudoku:\n";
            printBoard();
        }
        else
        {
            cout << "No solution exists\n";
        }
    }

    return 0;
}