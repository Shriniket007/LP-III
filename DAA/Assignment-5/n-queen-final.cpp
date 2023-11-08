#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at a specific position
bool isSafe(vector<int> &queens, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        //  queen placed in the same column || top left to the bottom right || top right to the bottom left
        if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row)
        {
            return false;
        }
    }
    return true;
}

// Function to solve the N-Queens problem and print the solutions
void solveNQueens(vector<int> &queens, int row, int n, int &solutionCount)
{
    if (row == n)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     cout << queens[i] << " ";
        // }
        // cout << endl;

        // A solution is found, print the solution number and the board
        cout << "Solution " << solutionCount << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (queens[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
        solutionCount++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(queens, row, col))
        {
            queens[row] = col;
            solveNQueens(queens, row + 1, n, solutionCount);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the board size: ";
    cin >> n;

    vector<int> queens(n, -1);
    int solutionCount = 1;
    solveNQueens(queens, 0, n, solutionCount);

    return 0;
}

// Time Complexity (TC): The time complexity of this backtracking algorithm is O(N!),
// Space Complexity (SC): The space complexity is O(N^2)
