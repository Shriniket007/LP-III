#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> solutions;

bool isSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
        {
            return false;
        }
    }
    return true;
}

void backtrack(vector<int> &board, int row, int n)
{
    if (row == n)
    {
        vector<string> formattedBoard(n, string(n, '0'));
        for (int i = 0; i < n; i++)
        {
            formattedBoard[i][board[i]] = '1';
        }
        solutions.push_back(formattedBoard);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            backtrack(board, row + 1, n);
            board[row] = -1;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the board size: ";
    cin >> n;

    vector<int> board(n, -1);
    backtrack(board, 0, n);

    int cnt = 1;
    if (!solutions.empty())
    {
        for (const vector<string> &solution : solutions)
        {
            cout << cnt << endl;
            cnt++;
            for (const string &row : solution)
            {
                cout << " " << row << " " << endl;
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
