#include <iostream>
#include <vector>

using namespace std;

bool issafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    int i = row;
    int j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int row, int n)
{
    if (row == n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (issafe(board, row, col, n))
        {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n))
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
    else
    {
        cout << "Something went wrong!" << endl;
    }

    return 0;
}