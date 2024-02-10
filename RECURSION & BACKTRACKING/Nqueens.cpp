//
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<string>> board, int n, int row, int col)
{
    // checking all above rowsS
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == "Q")
            return false;
    }

    // checking left diagonal element
    int i = row, j = col;
    while (i >= 0 and j >= 0)
    {
        if (board[i--][j--] == "Q")
            return false;
    }

    // check right upper diagonal
    i = row, j = col;
    while (i >= 0 and j < n)
    {
        if (board[i--][j++] == "Q")
            return false;
    }
    return true;
}
void printBoard(vector<vector<string>> board, int n);
bool solveNqueen(vector<vector<string>> board, int n, int i)
{
    // base case: if all queen are placed
    if (i == n)
    {
        printBoard(board, n);
        return true;
    }
    // rec case:
    // try to place  a queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, n, i, col))
        {
            board[i][col] = "Q"; // place the queen in this column
            bool success = solveNqueen(board, n, i + 1);
            if (success)
            {
                return true;
            }
            board[i][col] = "-"; // backtrack by removing queen from this cell
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> board(n, vector<string>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = "-";
        }
    }
    solveNqueen(board, n, 0);
    return 0;
}
void printBoard(vector<vector<string>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}