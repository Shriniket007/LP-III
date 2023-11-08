#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<vector<string>>> solutions;

bool isSafe(vector<vector<string>> &board, int row, int col, int n)
{
    // Check if there's a queen in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == "Q")
        {
            return false;
        }
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == "Q")
        {
            return false;
        }
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == "Q")
        {
            return false;
        }
    }

    return true;
}

void backtrack(vector<vector<string>> &board, int row, int n)
{
    if (row == n)
    {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = "Q";
            backtrack(board, row + 1, n);
            board[row][col] = ".";
        }
    }
}

int main()
{
    int n;
    cout << "Enter the board size: ";
    cin >> n;

    vector<vector<string>> board(n, vector<string>(n, "."));
    backtrack(board, 0, n);

    int cnt = 1;
    if (!solutions.empty())
    {
        for (const vector<vector<string>> &solution : solutions)
        {
            cout << "Solution " << cnt << ":" << endl;
            cnt++;
            for (const vector<string> &row : solution)
            {
                for (const string &cell : row)
                {
                    cout << " " << cell << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
