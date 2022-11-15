#include <iostream>
#include <vector>
#include <vector>
#include <regex>
#include <set>
using namespace std;

int getNumberOfAttackingQueenPlacements(int row, vector<int> columnPlacements, int boardSize);
bool isNonAttackingPlacement(int row, int col, vector<int> columnPlacements);
int nonAttackingQueens(int n);
void printBoard();
bool regexNumber(string numb);
void convert(vector<int> vec);
vector<vector<int>> cases;
set<vector<int>> cases2;

int main()
{
    int n;
    string sizeBoard;

    cout << "Input size of board: ";
    cin >> sizeBoard;

    if (!regexNumber(sizeBoard))
    {
        cout << "Input must be an integer\n";
        exit(0);
    }
    n = stoi(sizeBoard);

    // cout << "\nNumber of solutions: " << nonAttackingQueens(n) << endl;
    int size = nonAttackingQueens(n);
    if (size <= 3)
        cout << "Only one queen can be placed on the board\n";
    printBoard();
}

bool regexNumber(string numb) // Time: O(1)
{
    const regex expReg("^[0-9]+$");
    return regex_match(numb, expReg);
}

void convert(vector<int> vec)
{
    int size = vec.size();
    vector<vector<int>> board(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
        board[i][vec[i]] = 1;

    for (int i = 0; i < size; i++)
    {
        cout << "\t";
        for (int j = 0; j < size; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    return;
}

void printBoard()
{
    // int s;
    // cout << "Please select the solution you want to see: ";
    // cin >> s;
    int s = 1;

    auto first = cases2.begin();
    advance(first, s - 1);
    convert(*first);
}

int nonAttackingQueens(int n)
{
    vector<int> columnPlacements(n, 0);
    return getNumberOfAttackingQueenPlacements(0, columnPlacements, n);
}

int getNumberOfAttackingQueenPlacements(int row, vector<int> columnPlacements, int boardSize)
{
    if (row == boardSize)
        return 1;

    int validPlacements = 0;

    for (int col = 0; col < boardSize; col++)
    {
        if (isNonAttackingPlacement(row, col, columnPlacements))
        {

            columnPlacements[row] = col;

            if (row == boardSize - 1)
            {
                for (int i = 0; i < boardSize; i++)
                {
                    // cout << "col: " << i << " raw: " << columnPlacements[i] << endl;
                    cases.push_back(columnPlacements);
                    cases2.insert(columnPlacements);
                }
            }

            validPlacements += getNumberOfAttackingQueenPlacements(row + 1, columnPlacements, boardSize);
        }
    }
    return validPlacements;
}

bool isNonAttackingPlacement(int row, int col, vector<int> columnPlacements)
{
    int previousRow, columToCheck, sameColum, onDiagonal;

    for (previousRow = 0; previousRow < row; previousRow++)
    {
        columToCheck = columnPlacements[previousRow];
        sameColum = columToCheck == col;
        onDiagonal = abs(columToCheck - col) == row - previousRow;

        if (sameColum || onDiagonal)
            return false;
    }
    return true;
}