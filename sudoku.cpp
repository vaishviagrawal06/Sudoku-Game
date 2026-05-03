#include <iostream>
using namespace std;

//9x9 sudoku board
// 0 represent empty cell
int board[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},

    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},

    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

 // filled cells are fixed 
bool fixedCell[9][9];

void printBoard()
{
    cout << "\nSudoku Board:\n";
    for (int i = 0; i < 9; i++)
    {
        //horizontal separator print
        if (i % 3 == 0 && i != 0)
            cout << "-----------------------\n";

        for (int j = 0; j < 9; j++)
        {
            //vertical separator print
            if (j % 3 == 0 && j != 0)
                cout << "| ";

            // . represents empty cells
            if (board[i][j] == 0)
                cout << ". ";
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

// check valid move or not
bool isSafe(int row, int col, int num)
{
    // row : number already exist or not
    for (int i = 0; i < 9; i++)
        if (board[row][i] == num)
            return false;

            //column: number already exist or not
    for (int i = 0; i < 9; i++)
        if (board[i][col] == num)
            return false;

            //chexk 3x3 matrix
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

                //only when all moves are valid
    return true;
}

// find empty cell
//true if empty cell found
//false if not found
bool findEmpty(int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (board[row][col] == 0)
                return true;

    return false;
}

// backtraking to solve sudoku for auto solve 
bool solveSudoku()
{
    int row, col;

    //no empty cell sudoku is solved
    if (!findEmpty(row, col))
        return true;

        //enter number from 1 to 9 
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            board[row][col] = num;

            //recursively solve board
            if (solveSudoku())
                return true;

                //backtrack if wrong choice made
            board[row][col] = 0;
        }
    }
    return false;  //no valid number found
}

// check if sudoku is completly filled or not
bool isComplete()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == 0)
                return false;

    return true;
}

//user to play game
void playGame()
{
    int row, col, num;

    while (true)
    {
        printBoard();

        if (isComplete())
        {
            cout << "Congratulations! You solved the Sudoku!\n";
            break;
        }

        cout << "\nEnter row (1-9), column (1-9), number (0-9): ";
        cout<<"\n---OR---\n";
        cout << "Enter -1 -1 -1 to exit game: ";
        cin >> row >> col >> num;

        // Exit condition
        if (row == -1 && col == -1 && num == -1)
        {
            cout << "Exiting game...\n";
            break;
        }

        //0 based index par convert kar dega
        row--;
        col--;

        //check if number entered are under range or not
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

        //if 0 entered then erase option
        if (num == 0)
        {
            board[row][col] = 0;
            continue;
        }

        //move valid or not
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
    //initialize fixed cell
    initializeFixed();

        cout<<"\n========================\n";
        cout<<"   WELCOME TO SUDOKO    ";
        cout<<"\n========================\n";

    //menu
    int choice;
    cout << "1. Play Sudoku\n2. Auto Solve\nChoose option: ";
    cin >> choice;

    if (choice == 1)
    {
        //user plays manually
        playGame();
    }
    else if (choice == 2)
    {
        //computer solve automatically using backtracking
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